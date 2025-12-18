#include <iostream>
#include "Stack.hpp"
#include <string>
using namespace std;


namespace StackAppSpace {

    int priority(char c) {
        if (c == '^') return 5;
         if (c == '/') return 4;
        if (c == '*') return 3;
        if (c == '+') return 2;
        if (c == '-') return 1;
        return 0;
    }

    void InfixToPostFix() {
        string exp = "A*(B+C^K)";
        string postfix = "";
        Stack<char> stack;

        for (char c : exp) {
            if (c == '(' || c == '*' || c == '/' || c == '+' || c=='-' || c==')' || c == '^') {

                if (c == '(') {
                    stack.push(c);
                }else if (c == ')') {
                    while (stack.peek() != '(') {
                        postfix += stack.pop();
                    }
                    stack.pop();
                }
                else if (!stack.isEmpty() && priority(stack.peek()) >= priority(c)) {
                    postfix += stack.pop();
                    stack.push(c);
                }else {
                    stack.push(c);
                }
            }
            else {
                postfix +=c ;
            }
        }

        while (!stack.isEmpty()) {
            postfix += stack.pop();
        }
        cout << postfix << endl;

    }

    void PostFixToInfix() {
        string exp = "ABCK^+*";
        Stack<string> stack;

        for (char c : exp) {
            if (c == '^' || c == '*' || c == '/' || c == '+' || c == '-') {
                string infix = "";
                string exp1 = stack.pop();
                string exp2 = stack.pop();
                infix+= "(";
                infix += exp2;
                infix+= c;
                infix += exp1;
                infix+= ")";
                stack.push(infix);
            }else {
                string temp;
                temp.push_back(c);
                stack.push(temp);
            }
        }
        cout << stack.peek() << endl;
    }

    void App() {
        Stack<int> stack;
        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.push(40);
        stack.push(50);

        while (!stack.isEmpty()) {
            cout << stack.pop() << endl;
        }
    }


}