/*
Online stock span -> maximum consecutive days for which the stock price was less than or equal to current day

#Brute Approach :
Time Complexity : O(No.of days) -> loop runs only if it <=
space complexity : O(no. of next calls)


#Optimal Approach :
time complexity : O(2N)
space complexity : O(N)

*/

#include <bits/stdc++.h>
using namespace std;

class StockSpan
{
public:
    vector<int> arr;

    StockSpan()
    {
        // initialize empty vector
        arr = {};
    }

    int next(int val)
    {
        // 1. Add current value to the vector
        arr.push_back(val);

        // Current value counts as 1 day
        int cnt = 1;

        // 2. Check previous values and find consecutive days of increasing values
        for (int i = arr.size() - 2; i >= 0; i--)
        { //
            if (arr[i] <= val)
            {
                // 3. Increase count if value is less than or equal
                cnt++;
            }
            else
            {
                // Stop if we find a value greater than the current value
                break;
            }
        }

        return cnt;
    }
};

// optimal approach

class StockSpan_optimal
{
 public:
    int idx = -1;
    stack<pair<int, int>> st;

    StockSpan_optimal()
    {
        idx = -1;
          // Reinitialize the stack (clear the stack by creating a new one)
        st = stack<pair<int, int>>(); 
    }

    // 1. here one by one value will come
    int next(int val)
    {
        idx = idx + 1;

        // 2. whenever there is current ele >= top.first then simply pop it
        while (!st.empty() && val >= st.top().first)
        {
            st.pop();
        }


        // here top.second is the index of the value 
        int ans = idx - (st.empty() ? -1 : st.top().second);

        // // 3.if stack is empty then in pge vector insert -1 else top of the stack
        // pge[i] = st.empty() ? -1 : st.top();

        st.push({val, idx});

        return ans;
    }
};

int main()
{
    StockSpan stock; // Create an object of StockSpan
    StockSpan_optimal stk;


    // cout << stock.next(7) << endl;
    // cout << stock.next(2) << endl;
    // cout << stock.next(1) << endl;
    // cout << stock.next(3) << endl;
    // cout << stock.next(3) << endl;
    // cout << stock.next(1) << endl;
    // cout << stock.next(8) << endl;
    cout << stk.next(7) << endl;
    cout << stk.next(2) << endl;
    cout << stk.next(1) << endl;
    cout << stk.next(3) << endl;
    cout << stk.next(3) << endl;
    cout << stk.next(1) << endl;
    cout << stk.next(8) << endl;

    return 0;
}