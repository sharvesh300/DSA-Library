#include "Vector.hpp"
#include <iostream>

using namespace std;

namespace VectorApp{
    void App(){
        Vector<int> v;
        v.push_back(5);
        v.push_back(10);
        v.push_back(15);
        cout << v.back();
    }
}