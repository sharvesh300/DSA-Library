#include <iostream>
#include "List.hpp"
using namespace std;

namespace ListApp {
    void App() {
        List<int> l;
        l.add(45);
        l.add(55);
        l.add(65);


        List<int> l2;
        l2.add(4);
        l2.add(3);
        l2.add(5);

        List<int>::iterator it = l2.end();

        l2.splice(it,l);

        l2.printList();
       // l.printList();



    }
}