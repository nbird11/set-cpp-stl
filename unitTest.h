/***********************************************************************
 * Header:
 *    UNIT TEST
 * Summary:
 *    The base class to all the unit test classes
 * Author
 *    Br. Helfrich
 ************************************************************************/

#pragma once

#ifdef DEBUG
#undef assertUnit
#undef assertIndirect
#undef assertComplexFixture
#undef assertStandardFixture
#undef assertEmptyFixture

#undef logUnit

#define assertUnit(condition)     assertUnitParameters(condition, #condition, __LINE__, __FUNCTION__)
#define assertIndirect(condition) assertUnitParametersIndirect(condition, #condition, line, function, __LINE__, __FUNCTION__)
#define assertComplexFixture(x)   assertComplexFixtureParameters( x, __LINE__, __FUNCTION__)
#define assertStandardFixture(x)  assertStandardFixtureParameters(x, __LINE__, __FUNCTION__)
#define assertEmptyFixture(x)     assertEmptyFixtureParameters(   x, __LINE__, __FUNCTION__)

#define logUnit(x)                logParameters(x, #x, __LINE__, __FUNCTION__)

#include <iostream>  // for std::cerr
#include <string>    // for std::string
#include <vector>    // for std::vector
#include <map>       // for std::map
#include <sstream>   // for std::stringstream


class UnitTest
{
public:
   UnitTest() { reset(); }
   
private:
   // Base for Failure and Log types, so we can use polymorphism in reports
   struct Note
   {
      std::string expr;
      int lineNumber;
      enum Type { BASE, FAILURE, LOG } type = BASE;
   };

   // a test failure is a failure string and a line number
   struct Failure : public Note
   {
      Failure(const std::string& expr, int lineNumber) : Note{expr, lineNumber}
      {
         type = Type::FAILURE;
      }
   };
   // a test log is a log string and a line number
   struct Log : public Note
   {
      Log(const std::string& expr, int lineNumber) : Note{expr, lineNumber}
      {
         type = Type::LOG;
      }
   };

   // each test has a name (the key) and the list of notes(value).
   std::map<std::string, std::vector<Note>> tests;

   // Convert any type to string using stringstream
   template<typename T>
   std::string valueToString(const T& value)
   {
      std::stringstream ss;
      ss << value;
      return ss.str();
   }

protected:
   /*************************************************************
    * RESET
    * Reset the statistics
    *************************************************************/
   void reset()
   {
      tests.clear();
   }
   
   /*************************************************************
    * REPORT
    * Report the statistics
    *************************************************************/
   void report(const char * name)
   {    
      // enumerate the failures, if there are any
      for (auto & test : tests)
         if (!test.second.empty())
         {
            std::cerr << "\t" << test.first << "()\n";
            for (auto & note : test.second)
            {
               std::string type;
               switch (note.type)
               {
               case Note::Type::BASE:
                  type = "expr";
                  break;
               case Note::Type::FAILURE:
                  type = "condition";
                  break;
               case Note::Type::LOG:
                  type = "log";
                  break;
               }
               std::cerr << "\t\tline:" << note.lineNumber
                         << " " << type << ": " << note.expr << "\n";
            }
         }

      // Name the test case
      std::cerr << name << ":\t";

      // handle the no test case
      if (tests.empty())
      {
         std::cerr << "[There were no tests]\n";
         return;
      }

      // determine the success rate
      int numSuccess = 0;
      for (auto& test : tests)
      {
         // Check that test.second doesn't contain any Failure objects
         bool hasFailure = false;
         for (const auto& note : test.second)
            if (note.type == Note::Type::FAILURE)
               hasFailure = true;

         numSuccess += (hasFailure ? 0 : 1);
      }
      double successRate = (double)numSuccess / (double)tests.size();

      int numFailure = (int)tests.size() - numSuccess;

      // display the summary
      std::cerr.setf(std::ios::fixed | std::ios::showpoint);
      std::cerr.precision(1);
      std::cerr << "There" << (numFailure == 1 ? " was " : " were ")
         << numFailure << " failure" << (numFailure == 1 ? "" : "s") << " out of "
         << tests.size() << " test" << (tests.size() == 1 ? "" : "s") << " run for a success rate of : "
         << (successRate * 100.0) << "%\n";

   }
   
   /*************************************************************
    * ASSERT UNIT PARAMETERS
    * Custom assert code so we can see all the errors at once
    *************************************************************/
   void assertUnitParameters(bool condition, const char* conditionString,
                             int line, const char* func)
   {
      std::string sFunc(func);

      if (!condition)
      {
         // add a failure to the list of failures
         Failure failure{std::string(conditionString), line};
         tests[sFunc].push_back(failure);
      }
      else
      {
         // this ensures there is a placeholder for the successful test
         tests[sFunc];
      }
   }

   template <typename T>
   void logParameters(const T& x, const char* xExpr, int line, const char* func)
   {
      std::string sFunc(func);
      std::string sXExpr(valueToString(xExpr));
      std::string sX(valueToString(x));
      Log log{sXExpr+": "+sX, line};
      tests[sFunc].push_back(log);
   }
   
   
   /*************************************************************
    * ASSERT UNIT PARAMETERS INDIRECT
    * Custom assert code so we can see all the errors at once from
    * another function.
    *************************************************************/
   void assertUnitParametersIndirect(bool condition, const char* conditionString,
                                     int lineOriginal, const char* funcOriginal,
                                     int lineCheck, const char* funcCheck)
   {
      std::string sFunc(funcOriginal);
      
      if (!condition)
      {
         // add a failure to the list of failures
         Failure failure{std::string(conditionString), lineOriginal};
         tests[sFunc].push_back(failure);
      }
      else
      {
         // this ensures there is a placeholder for the successful test
         tests[sFunc];
      }
   }
};

#endif // DEBUG
