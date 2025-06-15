/**
 * @file Doubly_Linked_List.h
 * @brief A template class implementing a doubly linked list data structure
 * @author Eyad Sharkawy
 * @date 2025-05-02
 */

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdexcept> // For std::out_of_range
#include <iostream>  // For the print() method
#include <initializer_list>

/**
 * @brief A template class implementing a doubly linked list
 * @tparam T The type of elements stored in the list
 * 
 * This class provides a doubly linked list implementation with the following features:
 * - Bidirectional iteration
 * - Constant time insertion/deletion at both ends
 * - O(n) time insertion/deletion at arbitrary positions
 * - Memory efficient (no pre-allocation)
 * - Exception safe
 */
template <class T>
class Doubly_Linked_List {

private:
    /**
     * @brief Node structure for the doubly linked list
     */
    struct node {
        node* next;  ///< Pointer to the next node
        node* prev;  ///< Pointer to the previous node
        T item;      ///< The data stored in the node
    };

    node* front;     ///< Pointer to the first node
    node* back;      ///< Pointer to the last node
    unsigned long long length;  ///< Number of elements in the list

public:
    /**
     * @brief Default constructor
     * Creates an empty list
     */
    Doubly_Linked_List(): front(nullptr), back(nullptr), length(0) {}

    /**
     * @brief Initializer list constructor
     * @param array The initializer list containing elements to be added
     * Creates a list with elements from the initializer list
     */
    Doubly_Linked_List(std::initializer_list<T> array) : front(nullptr), back(nullptr), length(0) {
        for (const T& item : array) {
            push_back(item);
        }
    }

    /**
     * @brief Initializer list assignment operator
     * @param array The initializer list containing elements to be assigned
     * @return Reference to the modified list
     */
    Doubly_Linked_List& operator = (std::initializer_list<T> array) {
        this->clear();
        for (const T& item : array) {
            push_back(item);
        }
        return *this;
    }

    /**
     * @brief Copy constructor
     * @param other The list to be copied
     * Creates a deep copy of the other list
     */
    Doubly_Linked_List(const Doubly_Linked_List& other) : front(nullptr), back(nullptr), length(0) {
        node* temp = other.front;
        while (temp != nullptr) {
            this->push_back(temp->item);
            temp = temp->next;
        }
    }

    /**
     * @brief Copy assignment operator
     * @param other The list to be copied
     * @return Reference to the modified list
     */
    Doubly_Linked_List& operator = (const Doubly_Linked_List& other) {
        if (this == &other) {
            return *this;
        }
        this->clear();
        node* temp = other.front;
        while (temp != nullptr) {
            this->push_back(temp->item);
            temp = temp->next;
        }
        return *this;
    }

    /**
     * @brief Destructor
     * Frees all allocated memory
     */
    ~Doubly_Linked_List() {
        clear();
    }

    /**
     * @brief Get the number of elements in the list
     * @return The length of the list
     */
    [[nodiscard]] unsigned long long get_length() const {
        return length;
    }

    /**
     * @brief Check if the list is empty
     * @return true if the list is empty, false otherwise
     */
    [[nodiscard]] bool empty() const {
        return length == 0;
    }

    /**
     * @brief Add an element to the end of the list
     * @param new_item The element to be added
     */
    void push_back(T new_item) {
        node* new_node = new node{nullptr, nullptr, new_item};
        if (empty()) {
            front = new_node;
            back = new_node;
        }
        else {
            back->next = new_node;
            new_node->prev = back;
            back = new_node;
        }
        ++length;
    }

    /**
     * @brief Add an element to the beginning of the list
     * @param new_item The element to be added
     */
    void push_front(T new_item) {
        node* new_node = new node{nullptr, nullptr, new_item};
        if (empty()) {
            front = new_node;
            back = new_node;
        }
        else {
            front->prev = new_node;
            new_node->next = front;
            front = new_node;
        }
        ++length;
    }

    /**
     * @brief Insert an element at a specific position
     * @param index The position where the element should be inserted
     * @param new_item The element to be inserted
     * @throw std::out_of_range if index is out of range
     */
    void insert(const unsigned long long index, T new_item) {
        if (index > length) {
            throw std::out_of_range("Index out of range in insert()");
        }

        if (index == 0) {
            push_front(new_item);
        }
        else if (index == length) {
            push_back(new_item);
        }
        else {
            node* temp;
            if (index <= length / 2) {
                temp = front;
                for (unsigned long long i = 0; i < index; ++i) {
                    temp = temp->next;
                }
            }
            else {
                temp = back;
                for (unsigned long long i = length - 1; i > index; --i) {
                    temp = temp->prev;
                }
            }

            node* new_node = new node;
            new_node->item = new_item;
            new_node->next = temp;
            new_node->prev = temp->prev;
            temp->prev->next = new_node;
            temp->prev = new_node;

            ++length;
        }
    }

    /**
     * @brief Remove the last element from the list
     */
    void pop_back() {
        if (empty()) return;
        node* temp = back;
        if (front == back) {
            front = back = nullptr;
        } else {
            back = back->prev;
            back->next = nullptr;
        }
        delete temp;
        --length;
    }

    /**
     * @brief Remove the first element from the list
     */
    void pop_front() {
        if (empty()) return;
        node* temp = front;
        if (front == back) {
            front = back = nullptr;
        } else {
            front = front->next;
            front->prev = nullptr;
        }
        delete temp;
        --length;
    }

    /**
     * @brief Remove an element at a specific position
     * @param index The position of the element to be removed
     * @throw std::out_of_range if index is out of range
     */
    void erase(unsigned long long index) {
        if (index >= length) {
            throw std::out_of_range("Index out of range in erase()");
        }

        if (index == 0) {
            pop_front();
            return;
        }
        if (index == (length - 1)) {
            pop_back();
            return;
        }

        node* temp;
        if (index <= (length / 2)) {
            temp = front;
            for (unsigned long long i = 0; i < index; ++i) {
                temp = temp->next;
            }
        }
        else {
            temp = back;
            for (unsigned long long i = (length - 1); i > index; --i) {
                temp = temp->prev;
            }
        }
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        delete temp;
        --length;
    }

    /**
     * @brief Remove all elements from the list
     */
    void clear() {
        node* current = front;
        while (current != nullptr) {
            node* next_node = current->next;
            delete current;
            current = next_node;
        }
        front = back = nullptr;
        length = 0;
    }

    /**
     * @brief Reverse the order of elements in the list
     */
    void reverse() {
        if (empty() || length == 1) {
            return;
        }

        node* current = front;
        node* temp = nullptr;

        // Swap next and prev pointers for all nodes
        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;  // Move to next node (which is now in prev)
        }

        // Swap front and back pointers
        temp = front;
        front = back;
        back = temp;
    }

    /**
     * @brief Print the list contents to standard output
     */
    void print() const {
        node* temp = front;
        std::cout << "[ ";
        while (temp != nullptr) {
            std::cout << temp->item << ' ';
            temp = temp->next;
        }
        std::cout << ']' << std::endl;
    }

    /**
     * @brief Iterator class for the doubly linked list
     */
    class Iterator {
    private:
        node* curr;  ///< Current node pointer
        Doubly_Linked_List<T>* list;  ///< Reference to parent list

        explicit Iterator(node* p, Doubly_Linked_List<T>* l = nullptr) : curr(p), list(l) {}

    public:
        friend class Doubly_Linked_List<T>;

        Iterator(): curr(nullptr), list(nullptr) {}
        Iterator(const Iterator& other): curr(other.curr), list(other.list) {}

        Iterator& operator = (const Iterator& other) {
            if (this != &other) {
                curr = other.curr;
                list = other.list;
            }
            return *this;
        }

        bool operator == (const Iterator& other) const {
            return curr == other.curr;
        }

        bool operator != (const Iterator& other) const {
            return curr != other.curr;
        }

        T& operator* () {
            if (curr) {
                return curr->item;
            }
            throw std::runtime_error("Dereferencing a null iterator.");
        }

        Iterator& operator ++ () {
            if (curr) {
                curr = curr->next;
            }
            return *this;
        }

        Iterator operator ++ (int) {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }

        Iterator& operator -- () {
            if (!curr) {
                if (list && !list->empty()) {
                    curr = list->back;
                }
            } else {
                curr = curr->prev;
            }
            return *this;
        }

        Iterator operator -- (int) {
            Iterator temp = *this;
            --(*this);
            return temp;
        }

        T* operator -> () {
            if (!curr) {
                throw std::runtime_error("Cannot access member via end() iterator");
            }
            return &(curr->item);
        }
    };

    /**
     * @brief Get an iterator to the first element
     * @return Iterator pointing to the first element
     */
    Iterator begin() {
        return Iterator(front, this);
    }

    /**
     * @brief Get an iterator to the position after the last element
     * @return Iterator pointing to the end
     */
    Iterator end() {
        return Iterator(nullptr, this);
    }

    /**
     * @brief Access element at specified index
     * @param index The index of the element to access
     * @return Reference to the element at the specified index
     */
    T& operator[](const long long index) {
        if (index == 0) return this->front->item;

        if (index == (this->length - 1)) return this->back->item;

        if (index <= (this->length / 2)) {
            Iterator temp(this->front);
            for (unsigned long long i = 0; i < index; ++i) {
                ++temp;
            }
            return *temp;
        }

        Iterator temp(this->back);
        for (unsigned long long int i = (this->length - 1); i > index; --i) {
            --temp;
        }
        return *temp;
    }

    /**
     * @brief Access element at specified index with bounds checking
     * @param index The index of the element to access
     * @return Reference to the element at the specified index
     * @throw std::out_of_range if index is out of range
     */
    T& at(const long long index) {
        if (index < length) return this->operator[](index);
        throw std::out_of_range("Index out of range");
    }
};

#endif //DOUBLY_LINKED_LIST_H
