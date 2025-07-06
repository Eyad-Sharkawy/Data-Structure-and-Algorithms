/**
 * @file Linked_Stack.tpp
 * @brief Implementation file for the Linked_Stack template class.
 * @see Linked_Stack.h for class documentation.
 */

#include "Linked_Stack.hpp"

template <class T>
Linked_Stack<T>::Linked_Stack() : top(nullptr), length(0) {}

template <class T>
Linked_Stack<T>::~Linked_Stack() {
    clear();
}

template <class T>
Linked_Stack<T>::Linked_Stack(std::initializer_list<T> array) : top(nullptr), length(0) {
    for (const T& item : array) {
        push(item);
    }
}

template <class T>
Linked_Stack<T>& Linked_Stack<T>::operator=(std::initializer_list<T> array) {
    clear();
    for (const T& item : array) {
        push(item);
    }
    return *this;
}

template <class T>
Linked_Stack<T>::Linked_Stack(const Linked_Stack<T>& other) : top(nullptr), length(0) {
    node* temp = other.top;
    while (temp != nullptr) {
        push(temp->item);
        temp = temp->next;
    }
}

template <class T>
Linked_Stack<T>& Linked_Stack<T>::operator=(const Linked_Stack<T>& other) {
    if (this != &other) {
        clear();
        node* temp = other.top;
        while (temp != nullptr) {
            push(temp->item);
            temp = temp->next;
        }
    }
    return *this;
}

template <class T>
unsigned long long Linked_Stack<T>::get_length() const {
    return length;
}

template <class T>
bool Linked_Stack<T>::empty() const {
    return length == 0;
}

template <class T>
void Linked_Stack<T>::push(T new_item) {
    node* new_node = new node{top, new_item};
    top = new_node;
    ++length;
}

template <class T>
void Linked_Stack<T>::pop() {
    if (empty()) return;
    node* temp = top;
    top = top->next;
    delete temp;
    --length;
}

template <class T>
T& Linked_Stack<T>::top_item() {
    if (empty()) {
        throw std::runtime_error("Stack is empty");
    }
    return top->item;
}

template <class T>
void Linked_Stack<T>::clear() {
    while (!empty()) {
        pop();
    }
}

template <class T>
void Linked_Stack<T>::print() const {
    node* temp = top;
    std::cout << "[ ";
    while (temp != nullptr) {
        std::cout << temp->item << ' ';
        temp = temp->next;
    }
    std::cout << ']' << std::endl;
} 