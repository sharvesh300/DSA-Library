#include <iostream>
#ifndef QUEUE_H
#define QUEUE_H

template<class T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(T data,Node* next) {
            this->data = data;
            this->next = next;
        }
        Node(T data) {
            this->data = data;
            this->next = nullptr;
        }
    };
    Node* first;
    Node* last;
    public:
    int size;
    Queue();
    ~Queue();
    void enqueue(T data);
    T dequeue();
    bool isEmpty();

};

template<class T>
Queue<T>::~Queue() {
    while (first != nullptr) {
        Node* temp = first;
        first = first->next;
        delete temp;
    }
}
template<class T>
Queue<T>::Queue() {
    this->first = nullptr;
    this->last = nullptr;
    this->size = 0;
}

template<class T>
void Queue<T>::enqueue(T data) {
    if (size == 0) {
        first = new Node(data);
        last = first;
    }else {
        last->next = new Node(data);
        last = last->next;
    }
    size++;
}

template<class T>
T Queue<T>::dequeue() {
    if (size == 0) {
        throw std::out_of_range("Queue is empty");
    }
    Node* p = first;
    first = first->next;
    T data = p->data;
    delete p;
    size--;
    return data;
}

template<class T>
bool Queue<T>::isEmpty() {
    return size == 0;
}



#endif //QUEUE_H
