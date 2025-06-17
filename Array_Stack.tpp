/**
 * @file Array_Stack.tpp
 * @brief Implementation file for the Array_Stack template class.
 * @see Array_Stack.h for class documentation.
 */

#include "Array_Stack.h"

template <class T>
Array_Stack<T>::Array_Stack() : top(-1), capacity(10) {
    arr = new T[capacity];
}

template <class T>
Array_Stack<T>::~Array_Stack() {
    delete[] arr;
}

template <class T>
Array_Stack<T>::Array_Stack(std::initializer_list<T> array) : top(-1), capacity(array.size()) {
    arr = new T[capacity];
    for (const T& item : array) {
        push(item);
    }
}

template <class T>
Array_Stack<T>& Array_Stack<T>::operator=(std::initializer_list<T> array) {
    delete[] arr;
    top = -1;
    capacity = array.size();
    arr = new T[capacity];
    for (const T& item : array) {
        push(item);
    }
    return *this;
}

template <class T>
Array_Stack<T>::Array_Stack(const Array_Stack<T>& other) : top(other.top), capacity(other.capacity) {
    arr = new T[capacity];
    for (int i = 0; i <= top; ++i) {
        arr[i] = other.arr[i];
    }
}

template <class T>
Array_Stack<T>& Array_Stack<T>::operator=(const Array_Stack<T>& other) {
    if (this != &other) {
        delete[] arr;
        top = other.top;
        capacity = other.capacity;
        arr = new T[capacity];
        for (int i = 0; i <= top; ++i) {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

template <class T>
int Array_Stack<T>::get_length() const {
    return top + 1;
}

template <class T>
bool Array_Stack<T>::empty() const {
    return top == -1;
}

template <class T>
bool Array_Stack<T>::full() const {
    return top == capacity - 1;
}

template <class T>
void Array_Stack<T>::push(T new_item) {
    if (full()) {
        T* new_arr = new T[capacity * 2];
        for (int i = 0; i <= top; ++i) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        capacity *= 2;
    }
    arr[++top] = new_item;
}

template <class T>
void Array_Stack<T>::pop() {
    if (empty()) {
        throw std::underflow_error("Stack is empty");
    }
    --top;
}

template <class T>
T& Array_Stack<T>::top_item() {
    if (empty()) {
        throw std::underflow_error("Stack is empty");
    }
    return arr[top];
}

template <class T>
void Array_Stack<T>::print() const {
    std::cout << "[ ";
    for (int i = 0; i <= top; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << ']' << std::endl;
} 