#include <iostream>
#include "fixed_stack.hpp"

using namespace std;

namespace FixedStackApp {
    void App() {
        FixedStack<int> stack(3);
        stack.push(10);
        stack.push(20);
        stack.push(30);
        // stack.push(40);

        while (!stack.isEmpty()) {
            cout << stack.pop() << endl;
        }
    }
}