/*
1st approach :
    -  use stack ds with pair
    - one store is current value and 2nd min
    take the val push into the stack
    - when stack is empty min is first value
    - if not then store pair(val , min(val, st.top().second))

Time Complexity: O(1)
Space Complexity: O(2N)


2nd Approach :
Let’s take a variable that stores the minimum number. So whenever a push operation comes in just take that number put it in the stack and update the variable to the number. 

check whether current is less than the min
    - if smaller then min -> push this modified values i.e (2*val - min) and update min to the value of original number 
    - if it is not the case the push it only 

Time Complexity: O(1)
Space Complexity: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

class StackClass
{

    // creating the stack pair
    stack<pair<int, int>> st;

public:
    void push(int x)
    {
        // declaring the min which track the min of the stack
        int minValue;

        // condition check - if stack is empty
        if (st.empty())
        {
            minValue = x;
        }
            else
            {
                // if not then min is min of current value and top of stack
                minValue = min(x, st.top().second);
            }
        
        st.push({x,minValue});
    }


    // pop operation 
    void Pop(){
        st.pop();
    }

    int Top(){
        // first which contains the current value
        return st.top().first;
    }


    int getMin(){
        return st.top().second;

    }

};



class MinStack {
  stack < long long > st;
  long long mini;
  public:
    /* initialize your data structure here. */
    MinStack() {
      while (st.empty() == false) st.pop();
      mini = INT_MAX;
    }

  // Push operation
  void push(int value) {
    long long val = static_cast<long long>(value); // Convert to long long for safety
    if (st.empty()) {
      mini = val;  // Update the minimum value
      st.push(val); // Push the actual value
    } else {
      if (val < mini) {
        // If the new value is smaller than the current minimum,
        // push the encoded value and update the minimum
        st.push(2 * val * 1LL - mini);
        mini = val;
      } else {
        // Otherwise, push the actual value
        st.push(val);
      }
    }
  }
  void Pop() {
    if (st.empty()) return;
    long long el = st.top();
    st.pop();

    if (el < mini) {
      mini = 2 * mini - el;
    }
  }

  int Top() {
    if (st.empty()) return -1;

    long long el = st.top();
    if (el < mini) return mini;
    return el;
  }

  int getMin() {
    return mini;
  }
};

int main()
{

    StackClass s;
    MinStack ms ;

s.push(10);
s.push(1);
s.push(-6);
s.push(4);

ms.push(3);
ms.push(2);
ms.push(-2);
ms.Pop();
cout<<ms.getMin()<<endl;

s.Pop();
cout<<s.Top()<<endl;
cout<<s.getMin();

    return 0;
}