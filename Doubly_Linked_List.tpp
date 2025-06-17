// Implementation file for Doubly_Linked_List
// See Doubly_Linked_List.h for class documentation

#pragma once
#include "Doubly_Linked_List.h"

template<class T>
Doubly_Linked_List<T>::Doubly_Linked_List() : front(nullptr), back(nullptr), length(0) {}

template<class T>
Doubly_Linked_List<T>::~Doubly_Linked_List() {
    clear();
}

template<class T>
Doubly_Linked_List<T>::Doubly_Linked_List(std::initializer_list<T> array) : front(nullptr), back(nullptr), length(0) {
    for (const T& item : array) {
        push_back(item);
    }
}

template<class T>
Doubly_Linked_List<T> &Doubly_Linked_List<T>::operator=(std::initializer_list<T> array) {
    this->clear();
    for (const T& item : array) {
        push_back(item);
    }
    return *this;
}

template<class T>
Doubly_Linked_List<T>::Doubly_Linked_List(const Doubly_Linked_List &other) : front(nullptr), back(nullptr), length(0) {
    node* temp = other.front;
    while (temp != nullptr) {
        this->push_back(temp->item);
        temp = temp->next;
    }
}

template<class T>
Doubly_Linked_List<T> &Doubly_Linked_List<T>::operator=(const Doubly_Linked_List &other) {
    if (this != &other) {
        clear();
        node* temp = other.front;
        while (temp != nullptr) {
            this->push_back(temp->item);
            temp = temp->next;
        }
    }
    return *this;
}

template<class T>
unsigned long long Doubly_Linked_List<T>::get_length() const {
    return length;
}

template<class T>
bool Doubly_Linked_List<T>::empty() const {
    return length == 0;
}

template<class T>
void Doubly_Linked_List<T>::push_back(T new_item) {
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

template<class T>
void Doubly_Linked_List<T>::push_front(T new_item) {
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

template<class T>
void Doubly_Linked_List<T>::insert(const unsigned long long index, T new_item) {
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

template<class T>
void Doubly_Linked_List<T>::pop_back() {
    if (empty()) return;
    const node* temp = back;
    if (front == back) {
        front = back = nullptr;
    } else {
        back = back->prev;
        back->next = nullptr;
    }
    delete temp;
    --length;
}

template<class T>
void Doubly_Linked_List<T>::pop_front() {
    if (empty()) return;
    const node* temp = front;
    if (front == back) {
        front = back = nullptr;
    } else {
        front = front->next;
        front->prev = nullptr;
    }
    delete temp;
    --length;
}

template<class T>
void Doubly_Linked_List<T>::erase(const unsigned long long index) {
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

template<class T>
void Doubly_Linked_List<T>::clear() {
    node* current = front;
    while (current != nullptr) {
        node* next_node = current->next;
        delete current;
        current = next_node;
    }
    front = back = nullptr;
    length = 0;
}

template<class T>
void Doubly_Linked_List<T>::reverse() {
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

template<class T>
void Doubly_Linked_List<T>::print() const {
    node* temp = front;
    std::cout << "[ ";
    while (temp != nullptr) {
        std::cout << temp->item << ' ';
        temp = temp->next;
    }
    std::cout << ']' << std::endl;
}

template<class T>
Doubly_Linked_List<T>::Iterator::Iterator(node *p, Doubly_Linked_List<T> *l) : curr(p), list(l) {}

template<class T>
Doubly_Linked_List<T>::Iterator::Iterator(): curr(nullptr), list(nullptr) {}

template<class T>
Doubly_Linked_List<T>::Iterator::Iterator(const Iterator& other) : curr(other.curr), list(other.list) {}

template<class T>
typename Doubly_Linked_List<T>::Iterator &Doubly_Linked_List<T>::Iterator::operator=(const Iterator &other) {
    if (this != &other) {
        curr = other.curr;
        list = other.list;
    }
    return *this;
}

template<class T>
bool Doubly_Linked_List<T>::Iterator::operator==(const Iterator &other) const {
    return curr == other.curr;
}

template<class T>
bool Doubly_Linked_List<T>::Iterator::operator!=(const Iterator &other) const {
    return this->curr != other.curr;
}

template<class T>
T &Doubly_Linked_List<T>::Iterator::operator*() {
    if (curr) {
        return curr->item;
    }
    throw std::runtime_error("Dereferencing a null iterator.");
}

template<class T>
typename Doubly_Linked_List<T>::Iterator &Doubly_Linked_List<T>::Iterator::operator++() {
    if (curr) {
        curr = curr->next;
    }
    return *this;
}

template<class T>
typename Doubly_Linked_List<T>::Iterator Doubly_Linked_List<T>::Iterator::operator++(int) {
    Iterator temp = *this;
    ++(*this);
    return temp;
}

template<class T>
typename Doubly_Linked_List<T>::Iterator &Doubly_Linked_List<T>::Iterator::operator--() {
    if (!curr) {
        if (list && !list->empty()) {
            curr = list->back;
        }
        return *this;
    }
    curr = curr->prev;
    return *this;
}

template<class T>
typename Doubly_Linked_List<T>::Iterator Doubly_Linked_List<T>::Iterator::operator--(int) {
    Iterator temp = *this;
    --(*this);
    return temp;
}

template<class T>
T* Doubly_Linked_List<T>::Iterator::operator->() {
    if (!curr) {
        throw std::runtime_error("Cannot access member via end() iterator");
    }
    return &(curr->item);
}

template<class T>
typename Doubly_Linked_List<T>::Iterator Doubly_Linked_List<T>::begin() {
    return Iterator(front, this);
}

template<class T>
typename Doubly_Linked_List<T>::Iterator Doubly_Linked_List<T>::end() {
    return Iterator(nullptr, this);
}

template<class T>
T &Doubly_Linked_List<T>::operator[](const long long index) {
    if (index < 0 || index >= length) {
        throw std::out_of_range("Index out of range");
    }
    if (index < length / 2) {
        Iterator temp(front, this);
        for (long long i = 0; i < index; ++i) {
            ++temp;
        }
        return *temp;
    } else {
        Iterator temp(back, this);
        for (long long i = length - 1; i > index; --i) {
            --temp;
        }
        return *temp;
    }
}

template<class T>
T &Doubly_Linked_List<T>::at(const long long index) {
    if (index < 0 || index >= length) {
        throw std::out_of_range("Index out of range");
    }
    return operator[](index);
} 