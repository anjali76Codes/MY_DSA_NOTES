#include<bits/stdc++.h>
using namespace std;

class Stack {
public:
    int arr[100]; // Array to store stack elements (size 100, can be changed)
    int topIndex = -1; // Keeps track of the top of the stack

    // Push function to add elements to the stack
    void push(int val) {
        if (topIndex < 99) { // Check if stack is not full
            arr[++topIndex] = val;
        }
        else {
            cout << "Stack Overflow" << endl;
        }
    }

    // Pop function to remove elements from the stack
    void pop() {
        if (topIndex >= 0) {
            topIndex--;
        }
        else {
            cout << "Stack Underflow" << endl;
        }
    }

    // Function to get the top element of the stack
    int top() {
        if (topIndex >= 0) {
            return arr[topIndex];
        }
        else {
            cout << "Stack is empty" << endl;
            return -1; // Or some other sentinel value to indicate error
        }
    }

    // Check if the stack is empty
    bool Empty() {
        return topIndex == -1;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    // Pop and display elements from the stack
    while (!s.Empty()) {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}
