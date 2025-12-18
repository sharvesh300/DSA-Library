#ifndef STACK_H
#define STACK_H
#include <stdexcept>

template<class T>
class Stack {
    private:
    struct Node {
        T data;
        Node* next;

        Node(T data,Node* next) {
            this->data = data;
            this->next = next;
        }
    };
    Node* head;
    int size;

    public:
    Stack();
    void push(T data);
    T pop();
    T peek();
    bool isEmpty();
    ~Stack();
};

template<class T>
Stack<T>::~Stack() {
    while(head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

}


template<class T>
Stack<T>::Stack() {
    this->head = nullptr;
    this->size = 0;
}


template<class T>
void Stack<T>::push(T data) {
    head = new Node(data,head);
    this->size++;
}

template<class T>
bool Stack<T>::isEmpty() {
    return this->size == 0;
}

template<class T>
T Stack<T>::pop() {
    if (this->isEmpty()) {
        throw std::out_of_range("Stack is empty");
    }
    Node* temp = this->head;
    T data = this->head->data;
    this->head = this->head->next;
    delete temp;
    this->size--;
    return data;
}

template<class T>
T Stack<T>::peek() {
    if (this->isEmpty()) {
        throw std::out_of_range("Stack is empty");
    }
    return this->head->data;
}



#endif //STACK_H
