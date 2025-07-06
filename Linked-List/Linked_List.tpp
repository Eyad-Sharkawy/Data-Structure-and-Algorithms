/**
 * @file Linked_List.tpp
 * @brief Implementation file for the Linked_List template class.
 * @see Linked_List.h for class documentation.
 */

#include "Linked_List.hpp"

template <class T>
Linked_List<T>::Linked_List() : front(nullptr), length(0) {}

template <class T>
Linked_List<T>::~Linked_List() {
    clear();
}

template <class T>
Linked_List<T>::Linked_List(std::initializer_list<T> array) : front(nullptr), length(0) {
    for (const T& item : array) {
        push_back(item);
    }
}

template <class T>
Linked_List<T>& Linked_List<T>::operator=(std::initializer_list<T> array) {
    clear();
    for (const T& item : array) {
        push_back(item);
    }
    return *this;
}

template <class T>
Linked_List<T>::Linked_List(const Linked_List& other) : front(nullptr), length(0) {
    node* temp = other.front;
    while (temp != nullptr) {
        push_back(temp->item);
        temp = temp->next;
    }
}

template <class T>
Linked_List<T>& Linked_List<T>::operator=(const Linked_List& other) {
    if (this != &other) {
        clear();
        node* temp = other.front;
        while (temp != nullptr) {
            push_back(temp->item);
            temp = temp->next;
        }
    }
    return *this;
}

template <class T>
unsigned long long Linked_List<T>::get_length() const {
    return length;
}

template <class T>
bool Linked_List<T>::empty() const {
    return length == 0;
}

template <class T>
void Linked_List<T>::push_back(T new_item) {
    node* new_node = new node{nullptr, new_item};
    if (empty()) {
        front = new_node;
    } else {
        node* temp = front;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    ++length;
}

template <class T>
void Linked_List<T>::push_front(T new_item) {
    node* new_node = new node{front, new_item};
    front = new_node;
    ++length;
}

template <class T>
void Linked_List<T>::insert(const unsigned long long index, T new_item) {
    if (index > length) {
        throw std::out_of_range("Index out of range in insert()");
    }
    if (index == 0) {
        push_front(new_item);
    } else if (index == length) {
        push_back(new_item);
    } else {
        node* temp = front;
        for (unsigned long long i = 0; i < index - 1; ++i) {
            temp = temp->next;
        }
        node* new_node = new node{temp->next, new_item};
        temp->next = new_node;
        ++length;
    }
}

template <class T>
void Linked_List<T>::pop_back() {
    if (empty()) return;
    if (length == 1) {
        delete front;
        front = nullptr;
    } else {
        node* temp = front;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
    --length;
}

template <class T>
void Linked_List<T>::pop_front() {
    if (empty()) return;
    node* temp = front;
    front = front->next;
    delete temp;
    --length;
}

template <class T>
void Linked_List<T>::erase(unsigned long long index) {
    if (index >= length) {
        throw std::out_of_range("Index out of range in erase()");
    }
    if (index == 0) {
        pop_front();
    } else if (index == length - 1) {
        pop_back();
    } else {
        node* temp = front;
        for (unsigned long long i = 0; i < index - 1; ++i) {
            temp = temp->next;
        }
        node* del = temp->next;
        temp->next = del->next;
        delete del;
        --length;
    }
}

template <class T>
void Linked_List<T>::clear() {
    while (!empty()) {
        pop_front();
    }
}

template <class T>
void Linked_List<T>::reverse() {
    node* prev = nullptr;
    node* current = front;
    node* next = nullptr;
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    front = prev;
}

template <class T>
void Linked_List<T>::print() const {
    node* temp = front;
    std::cout << "[ ";
    while (temp != nullptr) {
        std::cout << temp->item << ' ';
        temp = temp->next;
    }
    std::cout << ']' << std::endl;
}

template <class T>
T& Linked_List<T>::operator[](const long long index) {
    if (index < 0 || static_cast<unsigned long long>(index) >= length) {
        throw std::out_of_range("Index out of range in operator[]");
    }
    node* temp = front;
    for (unsigned long long i = 0; i < index; ++i) {
        temp = temp->next;
    }
    return temp->item;
}

template <class T>
T& Linked_List<T>::at(const long long index) {
    if (index < 0 || static_cast<unsigned long long>(index) >= length) {
        throw std::out_of_range("Index out of range in at()");
    }
    return operator[](index);
} 