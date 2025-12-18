#ifndef HEAPSORTAPP_HPP
#define HEAPSORTAPP_HPP
#include "HeapSort.hpp"
#include <iostream>
using namespace std;

namespace HeapSortSpace
{
    void Demo()
    {
        int arr[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
        HeapSort<int> hs;
        hs.sort(arr, 10);
        for (int i = 0; i < 10; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

#endif
