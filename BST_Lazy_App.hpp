#include <iostream>
#include "BST_Lazy.hpp"

namespace BSTLazyApp {
    void App() {
        BinaryTreeLazy<int,int> k;
        k.Insert(5,6);
        k.Insert(5,7);
        k.Insert(10,8);
        k.Insert(3,9);
        k.Insert(4,10);
        k.Delete(3);

        k.PrintTree();
    }
}