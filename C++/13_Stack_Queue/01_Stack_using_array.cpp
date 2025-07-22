/*
stack is a linear data structure that can be any of data type follow the LIFO mechanism.



Time Complexity: O(N)

Space Complexity: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

int st[10];
int top = -1;

void push(int data)
{
    // when stack exceeds the size
    if (top >= 9) // Corrected the boundary condition
    {
        cout << "Stack is full" << endl;
        return; // Prevent further execution if the stack is full
    }

    top++;
    st[top] = data;
}

int pop()
{
    if (top == -1)
    {
        cout << "Stack is empty" << endl;
        return -1;
    }

    int poppedElement = st[top]; // Store the element to be popped
    top--;
    return poppedElement;
}

int getTop()
{
    if (top == -1)
    {
        cout << "Stack is empty" << endl;
        return -1;
    }

    return st[top];
}

// calculate the size
int Size()
{
    return top + 1;
}

int main()
{
    push(1);
    push(3);
    push(2);
    push(6);

    cout << "Top of stack before deleting any element: " << getTop() << endl;
    cout << "Size of stack before deleting any element: " << Size() << endl;
    cout << "The element deleted is: " << pop() << endl;
    cout << "Size of stack after deleting an element: " << Size() << endl;
    cout << "Top of stack after deleting an element: " << getTop() << endl;

    return 0;
}
