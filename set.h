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
 *       set                 : A class that represents a Set
 *       set::iterator       : An iterator through Set
 * Author
 *    Brock Hoskins, Nathan Bird
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
      set() : bst(BST<T>())
      {}
      set(const set& rhs) : bst(rhs.bst)
      {}
      set(set&& rhs) : bst(std::move(rhs.bst))
      {}
      set(const std::initializer_list<T>& il) : set()
      {
         insert(il);
      }
      template <class Iterator>
      set(Iterator first, Iterator last) : set()
      {
         insert(first, last); // TODO
      }
      ~set()
      {
         clear();
      }

      //
      // Assign
      //
      set& operator =(const set& rhs)
      {
         return *this;
      }
      set& operator =(set&& rhs)
      {
         return *this;
      }
      set& operator =(const std::initializer_list<T>& il)
      {
         return *this;
      }
      void swap(set& rhs) noexcept
      {}

      //
      // Iterator
      //
      class iterator;
      iterator begin() const noexcept
      {
         return bst.begin();
      }
      iterator end() const noexcept
      {
         return iterator(nullptr);
      }

      //
      // Access
      //
      iterator find(const T& t)
      {
         return bst.find(t);
      }

      //
      // Status
      //
      bool empty() const noexcept
      {
         return bst.size() == 0;
      }
      size_t size() const noexcept
      {
         return bst.size();
      }

      //
      // Insert
      //
      std::pair<iterator, bool> insert(const T& t)
      {
         return bst.insert(t, true /*keepUnique*/);
      }
      std::pair<iterator, bool> insert(T&& t)
      {
         return bst.insert(std::move(t), true /*keepUnique*/);
      }
      void insert(const std::initializer_list<T>& il)
      {
         for (const T& t : il)
            insert(t);
      }
      template <class Iterator>
      void insert(Iterator first, Iterator last)
      {
         while (first != last)
         {
            insert(*first);
            ++first;
         }
      }


      //
      // Remove
      //
      void clear() noexcept
      {
         bst.clear();
      }
      iterator erase(iterator& it)
      {
         return iterator();
      }
      size_t erase(const T& t)
      {
         return 99;
      }
      iterator erase(iterator& itBegin, iterator& itEnd)
      {
         return iterator();
      }

   private:

      custom::BST<T> bst;

   }; // class set


   /**************************************************
    * SET ITERATOR
    * An iterator through Set
    *************************************************/
   template <typename T>
   class set<T>::iterator
   {
      friend class ::TestSet; // give unit tests access to the privates
      friend class custom::set<T>;
   public:
      // constructors, destructors, and assignment operator
      iterator()
      {}
      iterator(const typename custom::BST<T>::iterator& itRHS)
      {}
      iterator(const iterator& rhs)
      {}
      iterator& operator =(const iterator& rhs)
      {
         return *this;
      }

      // equals, not equals operator
      bool operator !=(const iterator& rhs) const
      {
         return true;
      }
      bool operator ==(const iterator& rhs) const
      {
         return true;
      }

      // dereference operator: by-reference so we can modify the Set
      const T& operator *() const
      {
         return *(new T);
      }

      // prefix increment
      iterator& operator ++()
      {
         return *this;
      }

      // postfix increment
      iterator operator ++(int postfix)
      {
         return *this;
      }

      // prefix decrement
      iterator& operator --()
      {
         return *this;
      }

      // postfix decrement
      iterator operator --(int postfix)
      {
         return *this;
      }

   private:

      typename custom::BST<T>::iterator it;

   }; // class set::iterator



}; // namespace custom



