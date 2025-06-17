/**
 * @file Linked_Stack.h
 * @brief Declaration of a generic stack data structure implemented using a linked list.
 */

#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#include <stdexcept>
#include <iostream>
#include <initializer_list>

/**
 * @class Linked_Stack
 * @brief A generic stack implementation using a linked list.
 * @tparam T The type of elements stored in the stack.
 */
template <class T>
class Linked_Stack {
private:
    /**
     * @struct node
     * @brief Internal node structure for the linked stack.
     */
    struct node {
        node* next; ///< Pointer to the next node.
        T item;     ///< The data stored in the node.
    };

    node* top; ///< Pointer to the top node of the stack.
    unsigned long long length; ///< Number of elements in the stack.

public:
    /**
     * @brief Default constructor. Initializes an empty stack.
     */
    Linked_Stack();
    Linked_Stack(std::initializer_list<T> array);
    Linked_Stack& operator=(std::initializer_list<T> array);
    /**
     * @brief Destructor. Clears the stack and frees memory.
     */
    ~Linked_Stack();
    /**
     * @brief Copy constructor.
     * @param other The stack to copy from.
     */
    Linked_Stack(const Linked_Stack& other);
    /**
     * @brief Copy assignment operator.
     * @param other The stack to copy from.
     * @return Reference to this stack.
     */
    Linked_Stack& operator=(const Linked_Stack& other);
    /**
     * @brief Returns the number of elements in the stack.
     * @return The number of elements.
     */
    [[nodiscard]] unsigned long long get_length() const;
    /**
     * @brief Checks if the stack is empty.
     * @return True if the stack is empty, false otherwise.
     */
    [[nodiscard]] bool empty() const;
    /**
     * @brief Adds an element to the top of the stack.
     * @param new_item The element to add.
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
    void clear();
    /**
     * @brief Prints the contents of the stack to standard output.
     */
    void print() const;
};

#include "Linked_Stack.tpp"

#endif // LINKED_STACK_H
