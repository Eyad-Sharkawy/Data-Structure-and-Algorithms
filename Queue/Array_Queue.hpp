/**
 * @file Array_Queue.h
 * @brief Declaration of a generic queue data structure implemented using a fixed-size array.
 */

#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

#include <stdexcept>
#include <iostream>
#include <initializer_list>

/**
 * @class Array_Queue
 * @brief A generic queue implementation using a fixed-size array.
 * @tparam T The type of elements stored in the queue.
 */
template <class T>
class Array_Queue {
private:
    T* arr; ///< Pointer to the array storing queue elements.
    unsigned long long front; ///< Index of the front element in the queue.
    unsigned long long back; ///< Index of the rear element in the queue.
    unsigned long long capacity; ///< Maximum capacity of the queue.
    unsigned long long length; ///< Number of elements in the queue.

public:
    /**
     * @brief Default constructor. Initializes an empty queue with default capacity.
     */
    Array_Queue();
    Array_Queue(std::initializer_list<T> array);
    Array_Queue& operator=(std::initializer_list<T> array);
    /**
     * @brief Destructor. Frees the allocated memory.
     */
    ~Array_Queue();
    /**
     * @brief Copy constructor.
     * @param other The queue to copy from.
     */
    Array_Queue(const Array_Queue& other);
    /**
     * @brief Copy assignment operator.
     * @param other The queue to copy from.
     * @return Reference to this queue.
     */
    Array_Queue& operator=(const Array_Queue& other);
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
     * @brief Checks if the queue is full.
     * @return True if the queue is full, false otherwise.
     */
    [[nodiscard]] bool full() const;
    /**
     * @brief Adds an element to the rear of the queue.
     * @param new_item The element to add.
     * @throws std::overflow_error if the queue is full.
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

#include "Array_Queue.tpp"

#endif // ARRAY_QUEUE_H