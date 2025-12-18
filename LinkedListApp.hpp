#include "LinkedList.hpp"


namespace LinkedListApp {
    void App() {
        LinkedList<int> list;
        list.insertBySorting(50);
        list.insertBySorting(30);
        list.insertBySorting(60);
        list.printList();
        cout << endl;
        list.reverseList();
        list.printList();
    }
}