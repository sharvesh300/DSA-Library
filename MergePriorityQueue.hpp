#include <iostream>
#include <string>

#include "HeapSort.hpp"
#include "PriorityQueue.hpp"

using namespace std;

class Person {


    public:
    string name;
    int priority;
    Person(string name,int priority) {
        this->name = name;
        this->priority = priority;
    }

    Person() {

    }

    bool operator>(const Person& person) {
        return this->priority > person.priority;
    }

    bool operator<(const Person& person) {
        return this->priority < person.priority;
    }

};

namespace MergePriorityQueue {
    void App() {
        PriorityQueue<Person> priority_queue(4);
        PriorityQueue<Person> priority_queue2(10);
        Person arr[6];
        HeapSort<Person> priority_queue3; //< Person

        Person p1("sharvesh",2);
        Person p2("Vignes",4);
        Person p3("Patient",6);

        Person p4("Dhakshin",3);
        Person p5("Ravish",5);
        Person p6("Harini",7);

        priority_queue.insert(p1);
        priority_queue.insert(p2);
        priority_queue.insert(p3);

        priority_queue2.insert(p4);
        priority_queue2.insert(p5);
        priority_queue2.insert(p6);
        int i = 0;
        //O(m+n)
        while (!priority_queue.isEmpty()) {
            Person temp = priority_queue.getmax();
            arr[i] = temp;
            i++;
        }

        while (!priority_queue2.isEmpty()) {
            Person temp = priority_queue2.getmax();
            arr[i] = temp;
            i++;
        }
        //O((m+n)log(m+n))
        priority_queue3.sort(arr,i);

        for (int j = 0; j < i; j++) {
            cout << arr[j].name << ":" << arr[j].priority << endl;
        }

    }
}