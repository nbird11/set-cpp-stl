# C++ Set Implementation with BST

This project implements a Set container in C++ using a Binary Search Tree (BST) as the underlying data structure. The implementation provides an efficient, ordered collection that maintains unique elements with logarithmic time complexity for most operations.

## Overview

The Set is implemented through a template-based class that maintains elements in sorted order and ensures uniqueness. Key features include:

- Template-based implementation supporting any comparable data type
- Red-black tree balancing for guaranteed O(log n) operations
- Bidirectional iterator implementation
- Memory-efficient node management
- Support for both copy and move semantics
- STL-compatible interface

## Class Structure

### `set<T>`

The main set class template with one parameter:

- T: Type of element stored in the set

Key components:

- Uses a custom `BST<T>` as the underlying data structure
- `iterator`: Public bidirectional iterator class
- Standard container interface methods

### `set<T>::iterator`

The iterator class provides bidirectional traversal through the set:

- Wraps the underlying BST iterator
- Supports increment/decrement operations
- Provides read-only access to elements

### `BST<T>`

The underlying Binary Search Tree implementation:

- `BNode`: Internal node structure
- Red-black tree balancing
- Memory management
- Tree traversal algorithms

## Set Operations

The implementation includes several key operations:

### Core Operations

- `insert()`: Insert elements (maintains uniqueness)
- `erase()`: Remove elements by iterator or value
- `find()`: Search for elements
- `clear()`: Delete all elements
- `swap()`: Exchange two sets
- `size()`: Count elements
- `empty()`: Check if set is empty

### Iterator Support

- `begin()`: Get iterator to first element
- `end()`: Get iterator past the last element
- Bidirectional iteration support

### Memory Management

- Efficient node reuse in assignment operations
- Proper cleanup of unused nodes
- Prevention of memory leaks

## Usage Example

```cpp
#include "set.h"

// Create a set with integers
custom::set<int> s;

// Insert elements
s.insert(5);
s.insert(3);
s.insert(7);

// Find an element
auto it = s.find(3);
if (it != s.end())
    std::cout << "Found: " << *it << std::endl;

// Iterate through the set
for (auto it = s.begin(); it != s.end(); ++it)
    std::cout << *it << " ";  // Output: 3 5 7

// Remove an element
s.erase(3);

// Check if empty
if (!s.empty())
    std::cout << "Set size: " << s.size() << std::endl;
```

## Testing

The implementation includes comprehensive unit tests that verify:

- Element insertion and deletion
- Tree balancing
- Iterator functionality
- Copy and move operations
- Memory management
- Edge cases

## Files

- `set.h`: Main set implementation
- `bst.h`: Underlying Binary Search Tree implementation
- `testSet.h`: Unit tests for set
- `testBST.h`: Unit tests for BST
- `spy.h`: Spy implementation for precise testing measurements
- `unitTest.h`: Unit testing framework

## Implementation Details

The set is implemented using a red-black tree to ensure balanced tree operations:

- All operations maintain O(log n) time complexity
- Elements are stored in sorted order
- Duplicate elements are not allowed
- Iterator invalidation follows standard container rules

## Authors

Nathan Bird  
[nathanbirdka@gmail.com](mailto:nathanbirdka@gmail.com)

Brock Hoskins  
[](.)
