#include <iostream>

using namespace std;

#ifndef LIST_HPP
#define LIST_HPP

template<class T>
class List {

public:
    List();
    ~List();
    void add(const T& data);
    void printList();

private:
    struct Node {
        T data;
        Node *next;
        Node *prev;

        Node(const T& data,Node* prev,Node* next) {
            this->data = data;
            this->next = next;
            this->prev = prev;
        }

        explicit Node(const T& data) {
            this->data = data;
            this->next = nullptr;
            this->prev = nullptr;
        }
    };

    Node* head;
    Node* tail;

public:
    class const_iterator {
    public:
        const_iterator():curr(nullptr){}
        const T& operator*() const{
            return retrieve();
        }

        const_iterator& operator++() {
            if (curr != nullptr) curr = curr->next;
            return *this;
        }
        const_iterator operator++(int) {
            const_iterator old = *this;
            ++(*this);
            return old;
        }

        const_iterator operator+(int k) const{
            const_iterator old = *this;
            for (int i = 0; i < k; i++) {
                ++(old);

            }
            return old;
        }

        const_iterator& operator--() {
            if (this->curr != nullptr) {this->curr = this->curr->prev;}
            else {
                this->curr = list->tail;
            }
            return *this;
        }

        bool operator==(const const_iterator& other) const{
            return curr == other.curr;
        }

        bool operator!=(const const_iterator& other) const{
            return curr != other.curr;
        }


    protected:
        Node* curr;
        const List<T>* list;
        const_iterator(Node* curr,const List<T>* list) : curr(curr),list(list) {}
        const T& retrieve() const{
            return curr->data;
        }

        friend class List<T>;
    };

    class iterator : public const_iterator {
    public:
        iterator(){}

        T& operator*() {
            if (this->curr == nullptr) {
                return this->list->tail->data;
            }
            return this->curr->data;
        }

        const T& operator*() const {
            return const_iterator::operator*();
        }

        iterator& operator--() {
            if (this->curr != nullptr) {this->curr = this->curr->prev;}
            else {
                this->curr = this->list->tail;
            }
            return *this;
        }

        iterator operator--(int) {
            iterator old = *this;
            --(*this);
            return old;
        }

        iterator& operator++() {
            if (this->curr != nullptr) this->curr = this->curr->next;
            return *this;
        }




        iterator operator++(int) {
            iterator old = *this;
            ++(*this);
            return old;
        }
        bool operator==(const const_iterator& other) {
            return this->curr == other.curr;
        }

        bool operator!=(const const_iterator& other) {
            return this->curr != other.curr;
        }

        protected:
        iterator( Node *p ,const List<T>* list) : const_iterator( p ,list){}
        friend class List<T>;

    };

    iterator begin() {
        return iterator(head,this);
    }

    iterator end()  {
        return iterator(nullptr,this);
    }

    const_iterator cbegin() const {
        return const_iterator(head,this);
    }

    const_iterator cend() const {
        return const_iterator(nullptr,this);
    }

    void splice(iterator position, List<T>& lst) {

        if (lst.head == nullptr) {
            return;
        }

        if (head == nullptr) {
            head = lst.head;
            tail = lst.tail;
            lst.tail =  nullptr;
            lst.head = nullptr;
            return;
        }
        if (position.curr == nullptr) {
            tail->next = lst.head;
            lst.head->prev = tail;
            tail = lst.tail;

        }
        else if (position.curr->prev == nullptr) {
            lst.tail->next = position.curr;
            position.curr->prev = lst.tail;
            head = lst.head;

        } else {
            position.curr->prev->next = lst.head;
            lst.head->prev = position.curr->prev;
            lst.tail->next = position.curr;
            position.curr->prev = lst.tail;
        }
        lst.tail = nullptr;
        lst.head = nullptr;
    }



    List<T>(const List& rhs);

    List<T>& operator=(const List<T>& rhs) {
        if (this == &rhs) {
            return *this;
        }

        Node* curr = head;

        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }

        Node* p = rhs.head;
        while (p != nullptr) {
            add(p->data);
            p = p->next;
        }
        return *this;
    }

};

template<class T>
List<T>::List(const List &rhs) {
    operator=(rhs);
}


template<class T>
void List<T>::add(const T& data) {
    if (head == nullptr) {
        head = new Node(data);
        tail = head;
    }else {
        Node* newData = new  Node(data);
        newData->prev = tail;
        tail->next = newData;
        tail = newData;
    }
}

template<class T>
void List<T>::printList() {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

template<class T>
List<T>::List() {
    this->head = nullptr;
    this->tail = nullptr;
}

template<class T>
List<T>::~List() {
    Node* curr = this->head;
    while (curr != nullptr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
}

#endif