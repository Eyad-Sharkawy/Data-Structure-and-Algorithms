/**
 * @file Array_Queue.tpp
 * @brief Implementation file for the Array_Queue template class.
 * @see Array_Queue.h for class documentation.
 */

#include "Array_Queue.h"

template <class T>
Array_Queue<T>::Array_Queue() : front(0), back(-1), length(0), capacity(10) {
    arr = new T[capacity];
}

template <class T>
Array_Queue<T>::~Array_Queue() {
    delete[] arr;
}

template <class T>
Array_Queue<T>::Array_Queue(std::initializer_list<T> array) : front(0), back(-1), length(0), capacity(array.size()) {
    arr = new T[capacity];
    for (const T& item : array) {
        push(item);
    }
}

template <class T>
Array_Queue<T>& Array_Queue<T>::operator=(std::initializer_list<T> array) {
    delete[] arr;
    front = 0;
    back = -1;
    length = 0;
    capacity = array.size();
    arr = new T[capacity];
    for (const T& item : array) {
        push(item);
    }
    return *this;
}

template <class T>
Array_Queue<T>::Array_Queue(const Array_Queue<T>& other) : front(other.front), back(other.back), length(other.length), capacity(other.capacity) {
    arr = new T[capacity];
    for (int i = 0; i < length; ++i) {
        arr[(front + i) % capacity] = other.arr[(other.front + i) % capacity];
    }
}

template <class T>
Array_Queue<T>& Array_Queue<T>::operator=(const Array_Queue<T>& other) {
    if (this != &other) {
        delete[] arr;
        front = other.front;
        back = other.back;
        length = other.length;
        capacity = other.capacity;
        arr = new T[capacity];
        for (int i = 0; i < length; ++i) {
            arr[(front + i) % capacity] = other.arr[(other.front + i) % capacity];
        }
    }
    return *this;
}

template <class T>
bool Array_Queue<T>::empty() const {
    return length == 0;
}

template <class T>
bool Array_Queue<T>::full() const {
    return length == capacity;
}

template <class T>
void Array_Queue<T>::push(T new_item) {
    if (full()) {
        T* new_arr = new T[capacity * 2];
        for (int i = 0; i < length; ++i) {
            new_arr[i] = arr[(front + i) % capacity];
        }
        delete[] arr;
        arr = new_arr;
        front = 0;
        back = length - 1;
        capacity *= 2;
    }
    back = (back + 1) % capacity;
    arr[back] = new_item;
    ++length;
}

template <class T>
void Array_Queue<T>::pop() {
    if (empty()) return;
    front = (front + 1) % capacity;
    --length;
}

template <class T>
T& Array_Queue<T>::front_item() {
    if (empty()) {
        throw std::runtime_error("Queue is empty");
    }
    return arr[front];
}

template <class T>
T& Array_Queue<T>::back_item() {
    if (empty()) {
        throw std::runtime_error("Queue is empty");
    }
    return arr[back];
}

template <class T>
void Array_Queue<T>::clear() {
    front = 0;
    back = -1;
    length = 0;
}

template <class T>
void Array_Queue<T>::print() const {
    std::cout << "[ ";
    for (int i = 0; i < length; ++i) {
        std::cout << arr[(front + i) % capacity] << ' ';
    }
    std::cout << ']' << std::endl;
} 