#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <concepts>
#include <filesystem>
#include <stdexcept>

template<class T>
class PriorityQueue {

    public:
    PriorityQueue(int capacity);
    void insert(T data);
    T getmax();
    int size();
    bool isEmpty();
    bool changePriority(T data,int k);

    private:
    void fixUp(int k);
    void fixDown(int k);
    void swap(int i, int j);
    int capacity;
    int n;
    T* items;

};

template<class T>
bool PriorityQueue<T>::changePriority(T data, int k) {
    if (k <0 || k > capacity || n == 0) return false;

    int tmep = items[k];
    items[k] =data;
    if (data < items[k]) {
        fixDown(k);
    }else {
        fixUp(k);
    }

}


template<class T>
PriorityQueue<T>::PriorityQueue(int capacity) {
    this->capacity = capacity;
    this->n = 0;
    items = new T[capacity];
}

template<class T>
void PriorityQueue<T>::swap(int i,int j) {
    T temp = items[i];
    items[i] = items[j];
    items[j] = temp;
}

template<class T>
bool PriorityQueue<T>::isEmpty() {
    return n == 0;
}

template<class T>
int PriorityQueue<T>::size() {
    return n;
}

template<class T>
void PriorityQueue<T>::insert(T data) {
    if (n == capacity) {
        throw std::out_of_range("PriorityQueue is full");
    }
    items[n++] = data;
    fixUp(n-1);
}

template<class T>
T PriorityQueue<T>::getmax() {
    if (n == 0) {
        throw std::out_of_range("PriorityQueue is empty");
    }
    T temp = items[0];
    items[0] = items[--n];
    fixDown(0);
    return temp;
}


template<class T>
void PriorityQueue<T>::fixUp(int k) {
    int parent = (k - 1) / 2;
    while (k > 0 && items[parent] < items[k]) {
        swap(k, parent);
        k = parent;
    }
}

template<class T>
void PriorityQueue<T>::fixDown(int k) {

    while (k < n/2) {
        int left = 2 * k + 1;
        int right = left + 1;
        int largest = k;

        if (left < n && items[left] > items[largest]) {
            largest = left;
        }
        if (right < n && items[right] > items[largest]) {
            largest = right;
        }

        if (largest != k) {
            swap(k, largest);
            k = largest;
        }else {
            break;
        }

    }
}




#endif //PRIORITYQUEUE_H
