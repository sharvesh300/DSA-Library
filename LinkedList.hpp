#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>

template<class T>
class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    void insertAtHead(const T& ele);
    void printList();
    void swap(int i,int j);
    void insertBySorting(const T& ele);
    void reverseList();

private:
    struct Node {
        T data;
        Node* next;
         Node(const T& ele) {
            this->data = ele;
            this->next = nullptr;
        }

        Node(const T& ele, Node* next) {
             this->data = ele;
             this->next = next;
         }
    };

    Node* head;
    Node* tail;
    Node* findElement(int index);

};

template<class T>
 LinkedList<T>::Node* LinkedList<T>::findElement(int index) {
    if (index < 0) return nullptr;
    Node* current = head;

    for (int i = 0; i < index; i++) {
        current = current->next;
        if (current == nullptr) return nullptr;
    }
    return current;
}

template<class T>
void LinkedList<T>::swap(int i, int j) {
    if (i == j) return;
    if (i > j) return swap(j, i);

    Node* prev1 = findElement(i-1);
    Node* prev2 = findElement(j-1);

    Node* curr1 = findElement(i);
    Node* curr2 = prev2->next;


    if (prev1 != nullptr) prev1->next = curr2;
    if (prev2 != curr1) {
        Node* temp = curr1->next;
        prev2->next = curr1; //mapped 50 next to 60
        curr1->next = curr2->next; //mapped 30 to nullptr
        curr2->next = temp;

    }else {

        curr1->next = curr2->next;
        curr2->next = curr1;
    }

    cout << curr1->data << endl;

    if (curr1 == head) {
        head = curr2;
    }

    if (curr1->next == nullptr) {
        tail = curr1;
    }

}

template<class T>
void LinkedList<T>::insertBySorting(const T& ele) {

    if (head == nullptr) {
        head = new Node(ele);
        tail = head;
        return;
    }

    Node* curr = head;

    Node* prev = nullptr;
    while ( curr != nullptr && ele > curr->data) {
            prev = curr;
            curr = curr->next;
    }
    if (prev == nullptr) {
        head = new Node(ele,head);
    }else {
        prev->next = new Node(ele);
        if (curr != nullptr) {
            prev->next->next = curr;
        }else {
            tail = prev->next;
        }
    }
}

template<class T>
void LinkedList<T>::insertAtHead(const T &ele) {
    if (head == nullptr) {
        head = new Node(ele);
        tail = head;
    }
    else {
        head = new Node(ele, head);
    }
}

template<class T>
void LinkedList<T>::reverseList() {
    if (head == nullptr && head == tail) {
        return;
    }
    T data = head->data;

    Node* prev = nullptr;
    Node* curr = head;

    while (curr != nullptr) {
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    Node* temp = head;
    head = tail;
    tail = temp;
    tail->next = nullptr;
}

template<class T>
void LinkedList<T>::printList() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << "-->";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}



template<class T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    tail = nullptr;
}


template<class T>
LinkedList<T>::~LinkedList() {
    Node* curr = head;
    while (curr != nullptr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
}



#endif