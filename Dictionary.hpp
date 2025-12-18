#include <iostream>

#include "BST.hpp"
#include "queue.hpp"

using namespace std;

namespace DictionaryBST {
    void App() {
        string arr[5] = {"hi","i","am","sharvesh","sharvesh"};


        BST<string,int> dictionary;
        for (int i = 0; i < 5; i++) {
            int count = 0;
            if (dictionary.search(arr[i],count)) {
                dictionary.insert(arr[i],count+1);
            }else {
                dictionary.insert(arr[i],1);
            }

        }
        dictionary.PrintTree();
    }

}