#include <iostream>
#include "PriorityQueue.hpp"
using namespace std;

namespace PriorityQueueSpace {
    void App() {
        PriorityQueue<int> priority_queue(20);
        priority_queue.insert(10);
        priority_queue.insert(30);
        priority_queue.insert(60);
        priority_queue.insert(5);
        priority_queue.insert(2);

        while (!priority_queue.isEmpty()) {
           cout << priority_queue.getmax() << endl;
        }
    }
}