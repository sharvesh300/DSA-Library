#include <iostream>
#include "queue.hpp"

using namespace std;

namespace QueueApp {
    void queueApp() {
        Queue<int> q;
        q.enqueue(1);
        q.enqueue(2);

        q.enqueue(3);
        q.enqueue(4);
        q.enqueue(5);

        while (!q.isEmpty()) {
            cout << q.dequeue() << endl;
        }
        cout << !q.isEmpty() << endl;
    }
}