//
// Created by eyadd on 2025-04-20.
//

#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

#include <iostream>
#include <cassert>

using namespace std;

template <class t>
class Queue {
private:
    int MAX_LENGTH;
    int rear;
    int front;
    int length;
    t *array;

public:
    Queue(unsigned int size): MAX_LENGTH(size), rear(MAX_LENGTH - 1), front(0), length(0), array(new t[MAX_LENGTH]) {};
    Queue(): MAX_LENGTH(100), rear(MAX_LENGTH - 1), front(0), length(0), array(new t[MAX_LENGTH]) {};

    bool empty() {
        return length == 0;
    }

    bool isfull() {
        return length == MAX_LENGTH;
    }

    void enqueue(t new_item) {
        if (!isfull()) {
            rear = (1 + rear) % MAX_LENGTH;
            array[rear] = new_item;
            ++length;
        }
        else {
            cout << "Queue is full at Enqueue!" << endl;
        }
    }

    void dequeue() {
        if (!empty()) {
            front = (1 + front) % MAX_LENGTH;
            --length;
        }
        else {
            cout << "Queue is full at Dequeue!" << endl;
        }
    }

    void dequeue(t& new_item) {
        if (!empty()) {
            new_item = array[front];
            front = (1 + front) % MAX_LENGTH;
            --length;
        }
        else {
            cout << "Queue is full at Dequeue!" << endl;
        }
    }

    t get_front() {
        assert(!empty());
        return array[front];
    }

    t get_rear() {
        assert(!empty());
        return array[rear];
    }

    void print() {
        cout << "[ ";
        for (size_t i = front; i != rear; i = (1 + i) % MAX_LENGTH) {
            cout << array[i] << " ";
        }
        cout << array[rear] << " ]" << endl;
    }
};

#endif //ARRAY_QUEUE_H