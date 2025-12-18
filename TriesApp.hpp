#include <iostream>
#include "tries.hpp"

namespace TriesApp {
    void App() {
    Tries tries;
        char c[3] = {'a','n','d'};
        char c2[3] = {'a','n','t'};
        tries.insert("and");
        tries.insert("ant");
        tries.print();
        cout << tries.search("and") << endl;
        cout << tries.search("ans") <<endl;
        cout << tries.isPrefix("an") << endl;

    }
}