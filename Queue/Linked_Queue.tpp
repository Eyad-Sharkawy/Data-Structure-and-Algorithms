/**
 * @file Linked_Queue.tpp
 * @brief Implementation file for the Linked_Queue template class.
 * @see Linked_Queue.h for class documentation.
 */

#include "Linked_Queue.hpp"

template <class T>
Linked_Queue<T>::Linked_Queue() : front(nullptr), back(nullptr), length(0) {}

template <class T>
Linked_Queue<T>::~Linked_Queue() {
    clear();
}

template <class T>
Linked_Queue<T>::Linked_Queue(std::initializer_list<T> array) : front(nullptr), back(nullptr), length(0) {
    for (const T& item : array) {
        push(item);
    }
}

template <class T>
Linked_Queue<T>& Linked_Queue<T>::operator=(std::initializer_list<T> array) {
    clear();
    for (const T& item : array) {
        push(item);
    }
    return *this;
}

template <class T>
Linked_Queue<T>::Linked_Queue(const Linked_Queue<T>& other) : front(nullptr), back(nullptr), length(0) {
    node* temp = other.front;
    while (temp != nullptr) {
        push(temp->item);
        temp = temp->next;
    }
}

template <class T>
Linked_Queue<T>& Linked_Queue<T>::operator=(const Linked_Queue<T>& other) {
    if (this != &other) {
        clear();
        node* temp = other.front;
        while (temp != nullptr) {
            push(temp->item);
            temp = temp->next;
        }
    }
    return *this;
}

template <class T>
unsigned long long Linked_Queue<T>::get_length() const {
    return length;
}

template <class T>
bool Linked_Queue<T>::empty() const {
    return length == 0;
}

template <class T>
void Linked_Queue<T>::push(T new_item) {
    node* new_node = new node{nullptr, new_item};
    if (empty()) {
        front = back = new_node;
    } else {
        back->next = new_node;
        back = new_node;
    }
    ++length;
}

template <class T>
void Linked_Queue<T>::pop() {
    if (empty()) return;
    node* temp = front;
    front = front->next;
    delete temp;
    --length;
    if (empty()) {
        back = nullptr;
    }
}

template <class T>
T& Linked_Queue<T>::front_item() {
    if (empty()) {
        throw std::runtime_error("Queue is empty");
    }
    return front->item;
}

template <class T>
T& Linked_Queue<T>::back_item() {
    if (empty()) {
        throw std::runtime_error("Queue is empty");
    }
    return back->item;
}

template <class T>
void Linked_Queue<T>::clear() {
    while (!empty()) {
        pop();
    }
}

template <class T>
void Linked_Queue<T>::print() const {
    node* temp = front;
    std::cout << "[ ";
    while (temp != nullptr) {
        std::cout << temp->item << ' ';
        temp = temp->next;
    }
    std::cout << ']' << std::endl;
} 