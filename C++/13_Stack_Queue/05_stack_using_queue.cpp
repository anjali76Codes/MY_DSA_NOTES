/*
Time Complexity: O(N)
Space Complexity: O(N)
*/


#include <bits/stdc++.h>
using namespace std;

class stackClass
{
public:
    // queue ds to store the ele in queue
    queue<int> q;
    int size;

    void push(int ele)
    {

        // when only one ele is present in the queue so there is no need to do the changes in order that's why size is
        size = q.size();

        // first pushing the first ele into the queue
        q.push(ele);

        // loop for iterating the queue till size
        for (int i = 0; i < size; i++)
        {
            // here we are correcting the order of the queue which results the stack
            q.push(q.front());
            // after inserting the top of the queue remove it from the queue that results the correct order
            q.pop();
        }
    }

   int pop()
    {
        int n =  q.front();
       q.pop();
       return n;
        }
        
        
    

    void top()
    {
        // if the size of the queue is 0 then it means the stack is empty
        if (q.size() == 0)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            cout << q.front() << endl;
        }
    }

    void Size()
    {
        cout << size << endl;
    }
};

int main()
{
    stackClass ans;
    ans.push(1);
    ans.push(2);
    ans.push(3);
    ans.push(4);
   cout<<ans.pop();
    ans.top();
    ans.Size();

    return 0;
}