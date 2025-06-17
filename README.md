# Data Structures Implementation

This repository contains my personal implementations of various data structures in C++. These implementations were created as part of my learning journey to understand fundamental data structures and their operations.

## Implemented Data Structures

### 1. Doubly Linked List (`Doubly_Linked_List.h`, `Doubly_Linked_List.tpp`)
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

### 2. Single Linked List (`Linked_List.h`, `Linked_List.tpp`)
A template-based implementation of a singly linked list:
- Dynamic memory management
- Key operations:
  - Insertion: push_front, push_back, insert at index
  - Deletion: pop_front, pop_back, erase at index
  - List manipulation: reverse
  - Search functionality with find() method
  - Maintains both head and tail pointers

### 3. Array-based Queue (`Array_Queue.h`, `Array_Queue.tpp`)
A circular queue implementation using arrays:
- Fixed-size implementation with circular buffer
- Default size of 100 elements, customizable
- Key operations:
  - Enqueue and dequeue operations
  - Front and rear access
  - Full and empty state checking
  - Circular buffer implementation for efficient space usage

### 4. Linked List-based Queue (`Linked_Queue.h`, `Linked_Queue.tpp`)
A dynamic queue implementation using linked lists:
- Unlimited size (limited only by available memory)
- Key operations:
  - Enqueue and dequeue operations
  - Front and rear access
  - Queue clearing functionality
  - Dynamic memory management

### 5. Dynamic Array (`Linked_List_Array.h`, `Linked_List_Array.tpp`)
A template-based dynamic array implementation:
- Fixed maximum size with dynamic content
- Key operations:
  - Insertion: push_front, push_back, insert at position
  - Deletion: erase at position
  - Element access and update
  - Array state management (empty, full)

### 6. Array-based Stack (`Array_Stack.h`, `Array_Stack.tpp`)
A template-based stack implementation using arrays:
- Dynamic resizing when full
- Key operations:
  - Push and pop operations
  - Top element access
  - Full and empty state checking
  - Automatic capacity management

### 7. Linked List-based Stack (`Linked_Stack.h`, `Linked_Stack.tpp`)
A dynamic stack implementation using linked lists:
- Unlimited size (limited only by available memory)
- Key operations:
  - Push and pop operations
  - Top element access
  - Stack clearing functionality
  - Dynamic memory management

## Features Common Across Implementations

- Modern C++ implementation with template support
- Separation of interface (.h) and implementation (.tpp) files
- Exception handling and bounds checking
- Memory leak prevention through proper destructors
- Comprehensive error handling
- Print functionality for debugging and visualization
- Initializer list support for easy initialization
- Copy and move semantics support

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

## Project Structure
```
Data Structure/
├── Array_Queue.h          # Array-based queue interface
├── Array_Queue.tpp        # Array-based queue implementation
├── Array_Stack.h          # Array-based stack interface
├── Array_Stack.tpp        # Array-based stack implementation
├── Doubly_Linked_List.h   # Doubly linked list interface
├── Doubly_Linked_List.tpp # Doubly linked list implementation
├── Linked_List.h          # Single linked list interface
├── Linked_List.tpp        # Single linked list implementation
├── Linked_List_Array.h    # Dynamic array interface
├── Linked_List_Array.tpp  # Dynamic array implementation
├── Linked_Queue.h         # Linked list-based queue interface
├── Linked_Queue.tpp       # Linked list-based queue implementation
├── Linked_Stack.h         # Linked list-based stack interface
├── Linked_Stack.tpp       # Linked list-based stack implementation
├── main.cpp              # Main program with test cases
├── CMakeLists.txt        # CMake build configuration
└── README.md             # Project documentation
```

## Building the Project
The project uses CMake for building. To build:
```bash
mkdir build
cd build
cmake ..
cmake --build .
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