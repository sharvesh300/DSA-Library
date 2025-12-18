#include <iostream>
#include "AVL_Tree.hpp"



namespace AVL_TreeApp {
    void App() {
        AVLTree<int> d;

        for (int i = 0; i < 11; i++) {
            d.iterativeInsert(i);
        }
        d.print();
    }
}
