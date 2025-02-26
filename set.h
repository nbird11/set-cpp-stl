/***********************************************************************
* Header:
*    Set
* Summary:
 *      __      __     _______        __
 *     /  |    /  |   |  _____|   _  / /
 *     `| |    `| |   | |____    (_)/ /
 *      | |     | |   '_.____''.   / / _
 *     _| |_   _| |_  | \____) |  / / (_)
 *    |_____| |_____|  \______.' /_/
 *
 *    This will contain the class definition of:
*        set                 : A class that represents a Set
*        set::iterator       : An iterator through Set
* Author
*    <your names here>
************************************************************************/

#pragma once

#include <cassert>
#include <iostream>
#include "bst.h"
#include <memory>     // for std::allocator
#include <functional> // for std::less

class TestSet;        // forward declaration for unit tests

namespace custom
{

//   class TestSet;

/************************************************
 * SET
 * A class that represents a Set
 ***********************************************/
template <typename T>
class set
{
   friend class ::TestSet; // give unit tests access to the privates
public:
   
   // 
   // Construct
   //
   set() 
   { 
   }
   set(const set &  rhs)
   { 
   }
   set(set && rhs) 
   { 
   }
   set(const std::initializer_list <T> & il) 
   {
   }
   template <class Iterator>
   set(Iterator first, Iterator last) 
   {
   }
  ~set() { }

   //
   // Assign
   //

   set & operator = (const set & rhs)
   {
      return *this;
   }
   set & operator = (set && rhs)
   {
      return *this;
   }
   set & operator = (const std::initializer_list <T> & il)
   {
      return *this;
   }
   void swap(set& rhs) noexcept
   {
   }

   //
   // Iterator
   //

   class iterator;
   iterator begin() const noexcept 
   { 
      return iterator(); 
   }
   iterator end() const noexcept 
   { 
      return iterator(); 
   }

   //
   // Access
   //
   iterator find(const T& t) 
   { 
      return iterator(); 
   }

   //
   // Status
   //
   bool empty() const noexcept 
   { 
      return true;    
   }
   size_t size() const noexcept 
   { 
      return 99;     
   }

   //
   // Insert
   //
   std::pair<iterator, bool> insert(const T& t)
   {
      std::pair<iterator, bool> p(iterator(), true);
      return p;
   }
   std::pair<iterator, bool> insert(T&& t)
   {
      std::pair<iterator, bool> p(iterator(), true);
      return p;
   }
   void insert(const std::initializer_list <T>& il)
   {
   }
   template <class Iterator>
   void insert(Iterator first, Iterator last)
   {
   }


   //
   // Remove
   //
   void clear() noexcept 
   { 
   }
   iterator erase(iterator &it)
   { 
      return iterator(); 
   }
   size_t erase(const T & t) 
   {
      return 99;
   }
   iterator erase(iterator &itBegin, iterator &itEnd)
   {
      return iterator();
   }

private:
   
   custom::BST <T> bst;
};


/**************************************************
 * SET ITERATOR
 * An iterator through Set
 *************************************************/
template <typename T>
class set <T> :: iterator
{
   friend class ::TestSet; // give unit tests access to the privates
   friend class custom::set<T>;
public:
   // constructors, destructors, and assignment operator
   iterator() 
   { 
   }
   iterator(const typename custom::BST<T>::iterator& itRHS) 
   {  
   }
   iterator(const iterator & rhs) 
   { 
   }
   iterator & operator = (const iterator & rhs)
   {
      return *this;
   }

   // equals, not equals operator
   bool operator != (const iterator & rhs) const 
   { 
      return true; 
   }
   bool operator == (const iterator & rhs) const 
   { 
      return true; 
   }

   // dereference operator: by-reference so we can modify the Set
   const T & operator * () const 
   { 
      return *(new T); 
   }

   // prefix increment
   iterator & operator ++ ()
   {
      return *this;
   }

   // postfix increment
   iterator operator++ (int postfix)
   {
      return *this;
   }
   
   // prefix decrement
   iterator & operator -- ()
   {
      return *this;
   }
   
   // postfix decrement
   iterator operator-- (int postfix)
   {
      return *this;
   }
   
private:

   typename custom::BST<T>::iterator it;
};



}; // namespace custom



