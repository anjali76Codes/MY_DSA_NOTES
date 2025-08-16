/* 
1st approach : 
Time Complexity: O(N)
Space Complexity: O(2N)


2nd approach : 
Time Complexity: O(1 )
Space Complexity: O(2N)

*/

#include <bits/stdc++.h>
using namespace std;

struct QueueClass
{
    stack<int> s1, s2;

    // Push elements in queue
    void Push(int data)
    {
        // Pop out all elements from the stack s1 before inserting the next ele into this
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        // Insert the ele
        cout << "The element pushed is " << data << endl;
        s1.push(data);

        // Pop out elements from the stack s2 and push them into the stack s1 which ensure the order of the stack -> resulting the queue
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    // Pop the element from the Queue
    int Pop()
    {
        if (s1.empty())
        {
            cout << "Stack is empty";
            exit(0);
        }
        int val = s1.top();
        s1.pop();
        return val;
    }

    // Return the Topmost element from the Queue
    int Top()
    {
        if (s1.empty())
        {
            cout << "Stack is empty";
            exit(0);
        }
        return s1.top();
    }
    // Return the size of the Queue
    int size()
    {
        return s1.size();
    }
};

class Queue_2nd
{
public:
    stack<int> st1, st2;

    // Push an element into the queue
    void Push(int ele)
    {
        // Push the element directly into st1
        st1.push(ele);
        cout << "The element pushed is " << ele << endl;
    }

    // Pop an element from the queue
    int Pop()
    {
        if (st2.empty())
        {
            if (st1.empty())
            {
                cout << "Queue is empty" << endl;
                exit(0);
            }

            // Transfer all elements from st1 to st2
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }

        int x = st2.top();
        st2.pop();
        return x;
    }

    // Return the front element of the queue
    int Top()
    {
        if (st2.empty())
        {
            if (st1.empty())
            {
                cout << "Queue is empty" << endl;
                exit(0);
            }

            // Transfer all elements from st1 to st2
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }

        return st2.top();
    }

    // Return the size of the queue
    int Size()
    {
        return st1.size() + st2.size();
    }
};



int main()
{
    // QueueClass q;
    // q.Push(3);
    // q.Push(4);
    // cout << "The element poped is " << q.Pop() << endl;
    // q.Push(5);
    // cout << "The top of the queue is " << q.Top() << endl;
    // cout << "The size of the queue is " << q.size() << endl;

    Queue_2nd q2;
    q2.Push(1);
    q2.Push(2);
    q2.Push(3);
    q2.Push(4);
    cout << "The element poped is " << q2.Pop() << endl;
    q2.Push(5);
    cout << "The top of the queue is " << q2.Top() << endl;
    cout << "The size of the queue is " << q2.Size() << endl;
    return 0;
}