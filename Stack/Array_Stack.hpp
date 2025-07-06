/**
 * @file Array_Stack.h
 * @brief Declaration of a generic stack data structure implemented using a fixed-size array.
 */

#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include <stdexcept>
#include <iostream>
#include <initializer_list>

/**
 * @class Array_Stack
 * @brief A generic stack implementation using a fixed-size array.
 * @tparam T The type of elements stored in the stack.
 */
template <class T>
class Array_Stack {
private:
    T* arr; ///< Pointer to the array storing stack elements.
    int top; ///< Index of the top element in the stack.
    int capacity; ///< Maximum capacity of the stack.

public:
    /**
     * @brief Default constructor. Initializes an empty stack with default capacity.
     */
    Array_Stack();
    /**
     * @brief Destructor. Frees the allocated memory.
     */
    ~Array_Stack();
    /**
     * @brief Constructs a stack from an initializer list.
     * @param array The initializer list of elements.
     */
    Array_Stack(std::initializer_list<T> array);
    /**
     * @brief Assigns an initializer list to the stack.
     * @param array The initializer list of elements.
     * @return Reference to this stack.
     */
    Array_Stack& operator=(std::initializer_list<T> array);
    /**
     * @brief Copy constructor.
     * @param other The stack to copy from.
     */
    Array_Stack(const Array_Stack& other);
    /**
     * @brief Copy assignment operator.
     * @param other The stack to copy from.
     * @return Reference to this stack.
     */
    Array_Stack& operator=(const Array_Stack& other);
    /**
     * @brief Returns the number of elements in the stack.
     * @return The number of elements.
     */
    [[nodiscard]] int get_length() const;
    /**
     * @brief Checks if the stack is empty.
     * @return True if the stack is empty, false otherwise.
     */
    [[nodiscard]] bool empty() const;
    /**
     * @brief Checks if the stack is full.
     * @return True if the stack is full, false otherwise.
     */
    [[nodiscard]] bool full() const;
    /**
     * @brief Adds an element to the top of the stack.
     * @param new_item The element to add.
     * @throws std::overflow_error if the stack is full.
     */
    void push(T new_item);
    /**
     * @brief Removes the top element from the stack.
     * @throws std::underflow_error if the stack is empty.
     */
    void pop();
    /**
     * @brief Returns the top element of the stack.
     * @return Reference to the top element.
     * @throws std::underflow_error if the stack is empty.
     */
    T& top_item();
    /**
     * @brief Prints the contents of the stack to standard output.
     */
    void print() const;
};

#include "Array_Stack.tpp"

#endif // ARRAY_STACK_H
