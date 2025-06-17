/**
 * @file Linked_Queue.h
 * @brief Declaration of a generic queue data structure implemented using a linked list.
 */

#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include <stdexcept>
#include <iostream>
#include <initializer_list>

/**
 * @class Linked_Queue
 * @brief A generic queue implementation using a linked list.
 * @tparam T The type of elements stored in the queue.
 */
template <class T>
class Linked_Queue {
private:
    /**
     * @struct node
     * @brief Internal node structure for the linked queue.
     */
    struct node {
        node* next; ///< Pointer to the next node.
        T item;     ///< The data stored in the node.
    };
    node* front; ///< Pointer to the front node of the queue.
    node* back;  ///< Pointer to the rear node of the queue.
    unsigned long long length; ///< Number of elements in the queue.

public:
    /**
     * @brief Default constructor. Initializes an empty queue.
     */
    Linked_Queue();
    Linked_Queue(std::initializer_list<T> array);
    Linked_Queue& operator=(std::initializer_list<T> array);
    /**
     * @brief Destructor. Clears the queue and frees memory.
     */
    ~Linked_Queue();
    /**
     * @brief Copy constructor.
     * @param other The queue to copy from.
     */
    Linked_Queue(const Linked_Queue& other);
    /**
     * @brief Copy assignment operator.
     * @param other The queue to copy from.
     * @return Reference to this queue.
     */
    Linked_Queue& operator=(const Linked_Queue& other);
    /**
     * @brief Returns the number of elements in the queue.
     * @return The number of elements.
     */
    [[nodiscard]] unsigned long long get_length() const;
    /**
     * @brief Checks if the queue is empty.
     * @return True if the queue is empty, false otherwise.
     */
    [[nodiscard]] bool empty() const;
    /**
     * @brief Adds an element to the rear of the queue.
     * @param new_item The element to add.
     */
    void push(T new_item);
    /**
     * @brief Removes the front element from the queue.
     * @throws std::underflow_error if the queue is empty.
     */
    void pop();
    /**
     * @brief Returns the front element of the queue.
     * @return Reference to the front element.
     * @throws std::underflow_error if the queue is empty.
     */
    T& front_item();
    /**
     * @brief Returns the rear element of the queue.
     * @return Reference to the rear element.
     * @throws std::underflow_error if the queue is empty.
     */
    T& back_item();
    /**
     * @brief Clears the queue.
     */
    void clear();
    /**
     * @brief Prints the contents of the queue to standard output.
     */
    void print() const;
};

#include "Linked_Queue.tpp"

#endif // LINKED_QUEUE_H
