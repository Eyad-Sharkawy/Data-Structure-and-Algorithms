# Data Structures Implementation

This repository contains comprehensive implementations of various data structures in C++. These implementations were created as part of my learning journey to understand fundamental data structures and their operations.

## 🚀 Features

- **Modern C++ Implementation**: Uses C++11+ features with templates and RAII principles
- **Comprehensive Testing**: Automated test suite with visual feedback
- **Multiple Implementations**: Both array-based and linked list-based versions where applicable
- **Self-Balancing Trees**: AVL tree implementation with automatic balancing
- **Interactive Testing**: Menu-driven interface for testing individual or all data structures
- **Memory Safe**: Proper memory management with destructors and exception handling

## 📋 Implemented Data Structures

### 1. Doubly Linked List (`Doubly_Linked_List.hpp`, `Doubly_Linked_List.tpp`)
A template-based implementation of a doubly linked list with bidirectional traversal capabilities:
- Modern C++ implementation with template support
- Robust memory management with RAII principles
- Comprehensive iterator implementation with bidirectional traversal
- Exception-safe operations with proper error handling

#### Core Features
- **Memory Management**
  - Automatic memory cleanup through destructors
  - No memory leaks through proper resource management
  - Smart pointer usage for node management

- **Element Access**
  - Random access through operator[] with O(n/2) average case, O(1) for first/last element
  - Bounds-checked access through at() method
  - Front and back element access
  - Iterator-based access for efficient traversal

- **Modification Operations**
  - Insertion: push_front, push_back, insert at index
  - Deletion: pop_front, pop_back, erase at index
  - List manipulation: reverse, clear
  - Smart traversal optimization (chooses shortest path to target node)

- **Iterator Support**
  - Bidirectional iterators
  - Proper end() handling with decrement support
  - Const-correct implementation
  - Safe iterator operations with error checking

### 2. Single Linked List (`Linked_List.hpp`, `Linked_List.tpp`)
A template-based implementation of a singly linked list:
- Dynamic memory management
- Key operations:
  - Insertion: push_front, push_back, insert at index
  - Deletion: pop_front, pop_back, erase at index
  - List manipulation: reverse
  - Search functionality with find() method
  - Maintains both head and tail pointers

### 3. Array-based Queue (`Array_Queue.hpp`, `Array_Queue.tpp`)
A circular queue implementation using arrays:
- Fixed-size implementation with circular buffer
- Default size of 100 elements, customizable
- Key operations:
  - Enqueue and dequeue operations
  - Front and rear access
  - Full and empty state checking
  - Circular buffer implementation for efficient space usage

### 4. Linked List-based Queue (`Linked_Queue.hpp`, `Linked_Queue.tpp`)
A dynamic queue implementation using linked lists:
- Unlimited size (limited only by available memory)
- Key operations:
  - Enqueue and dequeue operations
  - Front and rear access
  - Queue clearing functionality
  - Dynamic memory management

### 5. Dynamic Array (`Linked_List_Array.hpp`, `Linked_List_Array.tpp`)
A template-based dynamic array implementation:
- Fixed maximum size with dynamic content
- Key operations:
  - Insertion: push_front, push_back, insert at position
  - Deletion: erase at position
  - Element access and update
  - Array state management (empty, full)

### 6. Array-based Stack (`Array_Stack.hpp`, `Array_Stack.tpp`)
A template-based stack implementation using arrays:
- Dynamic resizing when full
- Key operations:
  - Push and pop operations
  - Top element access
  - Full and empty state checking
  - Automatic capacity management

### 7. Linked List-based Stack (`Linked_Stack.hpp`, `Linked_Stack.tpp`)
A dynamic stack implementation using linked lists:
- Unlimited size (limited only by available memory)
- Key operations:
  - Push and pop operations
  - Top element access
  - Stack clearing functionality
  - Dynamic memory management

### 8. Binary Tree (AVL) (`Binary_Tree.hpp`, `Binary_Tree.tpp`)
A self-balancing binary search tree implementation using AVL algorithm:
- Automatic height balancing after insertions
- Four types of tree traversals (pre-order, in-order, post-order, level-order)
- Key operations:
  - Element insertion with automatic balancing
  - Tree traversal methods
  - Successor finding functionality
  - Height and balance factor calculations
  - Left and right rotations for balancing
- AVL balancing ensures O(log n) time complexity for all operations

## Features Common Across Implementations

- **Modern C++ Implementation**: Uses C++11+ features with templates and RAII principles
- **Separation of Concerns**: Interface (.hpp) and implementation (.tpp) files
- **Exception Safety**: Comprehensive exception handling and bounds checking
- **Memory Safety**: Memory leak prevention through proper destructors
- **Error Handling**: Robust error handling with meaningful error messages
- **Debugging Support**: Print functionality for debugging and visualization
- **Modern C++ Features**: Initializer list support, copy and move semantics
- **Template Support**: Generic implementations supporting any data type

## 📊 Performance Characteristics

| Data Structure | Access | Search | Insertion | Deletion | Space |
|---------------|--------|--------|-----------|----------|-------|
| Doubly Linked List | O(n) | O(n) | O(1) | O(1) | O(n) |
| Single Linked List | O(n) | O(n) | O(1) | O(1) | O(n) |
| Array-based Queue | O(1) | O(n) | O(1) | O(1) | O(n) |
| Linked Queue | O(1) | O(n) | O(1) | O(1) | O(n) |
| Array-based Stack | O(1) | O(n) | O(1) | O(1) | O(n) |
| Linked Stack | O(1) | O(n) | O(1) | O(1) | O(n) |
| Binary Tree (AVL) | O(log n) | O(log n) | O(log n) | O(log n) | O(n) |

## Usage Examples

### Doubly Linked List
```cpp
Doubly_Linked_List<int> list{1, 2, 3, 4, 5};
list.push_back(6);
list.push_front(0);
list.insert(3, 10);
list.print();  // Output: [ 0 1 2 10 3 4 5 6 ]
```

### Single Linked List
```cpp
Linked_List<int> list{1, 2, 3};
list.push_back(4);
list.push_front(0);
list.insert(2, 10);
list.print();  // Output: [ 0 1 10 2 3 4 ]
```

### Array Queue
```cpp
Array_Queue<int> queue{1, 2, 3};
queue.push(4);
queue.pop();
queue.print();  // Output: [ 2 3 4 ]
```

### Linked Queue
```cpp
Linked_Queue<int> queue{1, 2, 3};
queue.push(4);
queue.pop();
queue.print();  // Output: [ 2 3 4 ]
```

### Array Stack
```cpp
Array_Stack<int> stack{1, 2, 3};
stack.push(4);
stack.pop();
stack.print();  // Output: [ 1 2 3 ]
```

### Linked Stack
```cpp
Linked_Stack<int> stack{1, 2, 3};
stack.push(4);
stack.pop();
stack.print();  // Output: [ 1 2 3 ]
```

### Binary Tree (AVL)
```cpp
Binary_Tree<int> tree;
tree.insert(50);
tree.insert(30);
tree.insert(70);
tree.insert(20);
tree.insert(40);

// Traversals
tree.inOrder();    // Output: 20 30 40 50 70
tree.preOrder();   // Output: 50 30 20 40 70
tree.postOrder();  // Output: 20 40 30 70 50
tree.levelOrder(); // Output: 50 30 70 20 40
```

## Project Structure
```
Data Structure/
├── Binary-Tree/
│   ├── Binary_Tree.hpp     # Binary tree (AVL) interface
│   └── Binary_Tree.tpp     # Binary tree (AVL) implementation
├── Linked-List/
│   ├── Doubly_Linked_List.hpp   # Doubly linked list interface
│   ├── Doubly_Linked_List.tpp   # Doubly linked list implementation
│   ├── Linked_List.hpp          # Single linked list interface
│   ├── Linked_List.tpp          # Single linked list implementation
│   ├── Linked_List_Array.hpp    # Dynamic array interface
│   └── Linked_List_Array.tpp    # Dynamic array implementation
├── Stack/
│   ├── Array_Stack.hpp          # Array-based stack interface
│   ├── Array_Stack.tpp          # Array-based stack implementation
│   ├── Linked_Stack.hpp         # Linked list-based stack interface
│   └── Linked_Stack.tpp         # Linked list-based stack implementation
├── Queue/
│   ├── Array_Queue.hpp          # Array-based queue interface
│   ├── Array_Queue.tpp          # Array-based queue implementation
│   ├── Linked_Queue.hpp         # Linked list-based queue interface
│   └── Linked_Queue.tpp         # Linked list-based queue implementation
├── main.cpp                     # Main program with comprehensive test suite
├── CMakeLists.txt              # CMake build configuration
├── build.bat                   # Windows build script
└── README.md                   # Project documentation
```

## 🧪 Testing

The project includes a comprehensive test suite accessible through an interactive menu system. The test suite covers:

### Test Coverage
- **Constructor and Initialization**: Tests proper object creation
- **Core Operations**: Tests all primary data structure operations
- **Edge Cases**: Tests boundary conditions and error scenarios
- **Copy Semantics**: Tests copy constructors and assignment operators
- **Memory Management**: Ensures proper cleanup and no memory leaks

### Running Tests
```bash
# Build the project
mkdir build
cd build
cmake ..
cmake --build .

# Run the test suite
./Data_Structure.exe
```

### Test Menu Options
1. **Test Doubly Linked List** - Comprehensive doubly linked list testing
2. **Test Linked List** - Single linked list functionality testing
3. **Test Linked List Array** - Array-based linked list testing
4. **Test Array Stack** - Array-based stack operations
5. **Test Linked Stack** - Linked list-based stack operations
6. **Test Array Queue** - Array-based queue operations
7. **Test Linked Queue** - Linked list-based queue operations
8. **Test Binary Tree** - AVL tree operations and traversals
9. **Run All Tests** - Execute complete test suite
0. **Exit** - Close the program

### Test Output
Tests provide visual feedback with:
- ✓ for passed tests
- ✗ for failed tests
- Detailed console output for tree traversals

## 🏗️ Building the Project

The project uses CMake for building. To build:
```bash
mkdir build
cd build
cmake ..
cmake --build .
```

### Windows Build
For Windows users, you can also use the provided batch file:
```bash
build.bat
```

## 🚧 Future Additions
- **Hash Table implementation** - For O(1) average case lookups
- **Graph data structures** - Adjacency list/matrix implementations
- **Priority Queue** - Heap-based priority queue
- **Red-Black Tree** - Alternative self-balancing tree
- **B-Tree/B+ Tree** - For disk-based storage scenarios
- **Trie** - For string operations and autocomplete
- **Union-Find** - For graph algorithms and connectivity
- **Skip List** - Alternative to balanced trees

## Contributing
This is a personal learning project, but suggestions and improvements are welcome!

## License
This project is open source and available for educational purposes.