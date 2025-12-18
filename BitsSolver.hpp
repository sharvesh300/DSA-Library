#include <iostream>
#include "Stack.hpp"

using namespace std;

namespace BitsSolver {
    void solve(int *arr,int n) {
     //adding 1 and reversing array
        Stack<int> s;
        int rem = 1;
        for (int i = 0; i < n; i++) {
            int temp = arr[i] + rem;
            rem = temp/2;
            s.push(temp%2);
        }
        if (rem != 0) {
            s.push(rem);
        }
        while (!s.isEmpty()) {
            cout << s.pop() << "";
        }
    }
}