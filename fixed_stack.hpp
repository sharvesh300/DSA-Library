#ifndef FIXED_STACK_H
#define FIXED_STACK_H
#include <stdexcept>

template<class T>
class FixedStack {

public:
    FixedStack(int capacity);
    void push(T x);
    T pop();
    T peek();
    bool isEmpty();
    int size();
    ~FixedStack();

private:
    T* items;
    int n;
    int capacity;

};
template<class T>
FixedStack<T>::~FixedStack() {
    delete[] items;
}


template<class T>
FixedStack<T>::FixedStack(int capacity) {
    this->items = new T[capacity];
    this->n = 0;
    this->capacity = capacity;
}

template<class T>
void FixedStack<T>::push(T x) {
    if (n >= capacity) {
        throw std::overflow_error("Stack overflow");
    }
    this->items[n++] = x;
}

template<class T>
T FixedStack<T>::pop() {
    if (n == 0) {
        throw std::underflow_error("Stack underflow");
    }
    return items[--n];
}

template<class T>
bool FixedStack<T>::isEmpty() {
    return this->n == 0;
}

template<class T>
int FixedStack<T>::size() {
    return this->n;
}

template<class T>
T FixedStack<T>::peek() {
    if (n == 0) {
        throw std::underflow_error("Stack is empty");
    }
    return this->items[this->n - 1];
}



#endif
