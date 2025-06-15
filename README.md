# Data Structures Implementation

This repository contains my personal implementations of various data structures in C++. These implementations were created as part of my learning journey to understand fundamental data structures and their operations.

## Implemented Data Structures

### 1. Doubly Linked List (`Doubly_Linked_List.h`)
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

- **Initialization and Assignment**
  - Default constructor
  - Initializer list constructor
  - Copy constructor and assignment operator
  - Move semantics support

#### Usage Example
```cpp
// Create and initialize a list
Doubly_Linked_List<int> list{1, 2, 3, 4, 5};

// Add elements
list.push_back(6);
list.push_front(0);
list.insert(3, 10);

// Access elements
int first = list[0];
int last = list.at(list.get_length() - 1);

// Iterate through the list
for (auto it = list.begin(); it != list.end(); ++it) {
    std::cout << *it << " ";
}

// Reverse iteration
for (auto it = list.end(); it != list.begin(); --it) {
    std::cout << *it << " ";
}

// List manipulation
list.reverse();
list.clear();
```

#### Performance Characteristics
- Insertion/Deletion at ends: O(1)
- Insertion/Deletion at arbitrary position: O(n)
- Random access: O(n/2) average case, O(1) for first/last element
- Space complexity: O(n)
- Iterator operations: O(1)

### 2. Single Linked List (`Linked_List.h`)
A template-based implementation of a singly linked list:
- Dynamic memory management
- Key operations:
  - Insertion: push_front, push_back, insert at index
  - Deletion: pop_front, pop_back, erase at index
  - List manipulation: reverse
  - Search functionality with find() method
  - Maintains both head and tail pointers

### 3. Array-based Queue (`Array_Queue.h`)
A circular queue implementation using arrays:
- Fixed-size implementation with circular buffer
- Default size of 100 elements, customizable
- Key operations:
  - Enqueue and dequeue operations
  - Front and rear access
  - Full and empty state checking
  - Circular buffer implementation for efficient space usage

### 4. Linked List-based Queue (`Linked_Queue.h`)
A dynamic queue implementation using linked lists:
- Unlimited size (limited only by available memory)
- Key operations:
  - Enqueue and dequeue operations
  - Front and rear access
  - Queue clearing functionality
  - Dynamic memory management

### 5. Dynamic Array (`Linked_List_Array.h`)
A template-based dynamic array implementation:
- Fixed maximum size with dynamic content
- Key operations:
  - Insertion: push_front, push_back, insert at position
  - Deletion: erase at position
  - Element access and update
  - Array state management (empty, full)

## Features Common Across Implementations

- Modern C++ implementation
- Template-based design for type flexibility
- Exception handling and bounds checking
- Memory leak prevention through proper destructors
- Comprehensive error handling
- Print functionality for debugging and visualization

## Usage Examples

### Doubly Linked List
```cpp
Doubly_Linked_List<int> list;
list.push_back(1);
list.push_front(0);
list.insert(1, 2);
list.print();  // Output: [ 0 2 1 ]
```

### Single Linked List
```cpp
Single_Linked_List<int> list;
list.push_back(1);
list.push_front(0);
list.insert(1, 2);
list.print();  // Output: [ 0 2 1 ]
```

### Array Queue
```cpp
Queue<int> queue(10);  // Queue of size 10
queue.enqueue(1);
queue.enqueue(2);
queue.print();  // Output: [ 1 2 ]
```

### Linked Queue
```cpp
Queue<int> queue;
queue.enqueue(1);
queue.enqueue(2);
queue.print();  // Output: [ 1 2 ]
```

### Dynamic Array
```cpp
Array<int> arr(10);  // Array of max size 10
arr.push_back(1);
arr.push_front(0);
arr.print();  // Output: [ 0 1 ]
```

## Future Additions
- Binary Search Tree implementation
- Hash Table implementation
- Graph data structures
- Priority Queue
- More advanced tree structures

## Contributing
This is a personal learning project, but suggestions and improvements are welcome!

## License
This project is open source and available for educational purposes.