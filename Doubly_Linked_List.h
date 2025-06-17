/**
 * @file Doubly_Linked_List.h
 * @brief Declaration of a generic doubly linked list data structure with iterator support.
 */

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
#include <initializer_list>
#include <stdexcept>

/**
 * @class Doubly_Linked_List
 * @brief A generic doubly linked list implementation supporting bidirectional iteration.
 * @tparam T The type of elements stored in the list.
 */
template <class T>
class Doubly_Linked_List {
private:
    /**
     * @struct node
     * @brief Internal node structure for the doubly linked list.
     */
    struct node {
        node* next; ///< Pointer to the next node.
        node* prev; ///< Pointer to the previous node.
        T item;     ///< The data stored in the node.
    };
    node* front; ///< Pointer to the first node in the list.
    node* back;  ///< Pointer to the last node in the list.
    unsigned long long length; ///< Number of elements in the list.

public:
    /**
     * @brief Default constructor. Initializes an empty list.
     */
    Doubly_Linked_List();
    /**
     * @brief Destructor. Clears the list and frees memory.
     */
    ~Doubly_Linked_List();
    /**
     * @brief Constructs a list from an initializer list.
     * @param array The initializer list of elements.
     */
    Doubly_Linked_List(std::initializer_list<T> array);
    /**
     * @brief Assigns an initializer list to the list.
     * @param array The initializer list of elements.
     * @return Reference to this list.
     */
    Doubly_Linked_List& operator=(std::initializer_list<T> array);
    /**
     * @brief Copy constructor.
     * @param other The list to copy from.
     */
    Doubly_Linked_List(const Doubly_Linked_List& other);
    /**
     * @brief Copy assignment operator.
     * @param other The list to copy from.
     * @return Reference to this list.
     */
    Doubly_Linked_List& operator=(const Doubly_Linked_List& other);
    /**
     * @brief Returns the number of elements in the list.
     * @return The length of the list.
     */
    [[nodiscard]] unsigned long long get_length() const;
    /**
     * @brief Checks if the list is empty.
     * @return True if the list is empty, false otherwise.
     */
    [[nodiscard]] bool empty() const;
    /**
     * @brief Adds an element to the end of the list.
     * @param new_item The element to add.
     */
    void push_back(T new_item);
    /**
     * @brief Adds an element to the front of the list.
     * @param new_item The element to add.
     */
    void push_front(T new_item);
    /**
     * @brief Inserts an element at a specific index.
     * @param index The position to insert at.
     * @param new_item The element to insert.
     */
    void insert(const unsigned long long index, T new_item);
    /**
     * @brief Removes the last element from the list.
     */
    void pop_back();
    /**
     * @brief Removes the first element from the list.
     */
    void pop_front();
    /**
     * @brief Removes the element at a specific index.
     * @param index The position of the element to remove.
     */
    void erase(unsigned long long index);
    /**
     * @brief Removes all elements from the list.
     */
    void clear();
    /**
     * @brief Reverses the order of the elements in the list.
     */
    void reverse();
    /**
     * @brief Prints the contents of the list to standard output.
     */
    void print() const;
    /**
     * @brief Provides random access to elements by index.
     * @param index The index of the element.
     * @return Reference to the element at the given index.
     * @throws std::out_of_range if the index is invalid.
     */
    T& operator[](const long long index);
    /**
     * @brief Provides checked access to elements by index.
     * @param index The index of the element.
     * @return Reference to the element at the given index.
     * @throws std::out_of_range if the index is invalid.
     */
    T& at(const long long index);

    /**
     * @class Iterator
     * @brief Bidirectional iterator for the doubly linked list.
     */
    class Iterator {
    private:
        node* curr; ///< Pointer to the current node.
        Doubly_Linked_List<T>* list; ///< Pointer to the parent list.
    public:
        /**
         * @brief Constructs an iterator for a given node and list.
         * @param p Pointer to the node.
         * @param l Pointer to the parent list.
         */
        Iterator(node* p, Doubly_Linked_List<T>* l);
        /**
         * @brief Default constructor. Creates an end iterator.
         */
        Iterator();
        /**
         * @brief Copy constructor.
         * @param other The iterator to copy from.
         */
        Iterator(const Iterator& other);
        /**
         * @brief Assignment operator.
         * @param other The iterator to assign from.
         * @return Reference to this iterator.
         */
        Iterator& operator=(const Iterator& other);
        /**
         * @brief Checks if two iterators are equal.
         * @param other The iterator to compare with.
         * @return True if equal, false otherwise.
         */
        bool operator==(const Iterator& other) const;
        /**
         * @brief Checks if two iterators are not equal.
         * @param other The iterator to compare with.
         * @return True if not equal, false otherwise.
         */
        bool operator!=(const Iterator& other) const;
        /**
         * @brief Dereferences the iterator to access the element.
         * @return Reference to the element.
         */
        T& operator*();
        /**
         * @brief Advances the iterator to the next element (prefix).
         * @return Reference to this iterator.
         */
        Iterator& operator++();
        /**
         * @brief Advances the iterator to the next element (postfix).
         * @return Iterator before increment.
         */
        Iterator operator++(int);
        /**
         * @brief Moves the iterator to the previous element (prefix).
         * @return Reference to this iterator.
         */
        Iterator& operator--();
        /**
         * @brief Moves the iterator to the previous element (postfix).
         * @return Iterator before decrement.
         */
        Iterator operator--(int);
        /**
         * @brief Accesses the element pointer.
         * @return Pointer to the element.
         */
        T* operator->();
    };

    /**
     * @brief Returns an iterator to the beginning of the list.
     * @return Iterator to the first element.
     */
    Iterator begin();
    /**
     * @brief Returns an iterator to the end of the list.
     * @return Iterator to one past the last element.
     */
    Iterator end();
};

#include "Doubly_Linked_List.tpp"

#endif // DOUBLY_LINKED_LIST_H
