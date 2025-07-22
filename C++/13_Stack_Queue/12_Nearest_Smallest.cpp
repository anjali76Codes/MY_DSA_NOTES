/*
This is algorithm is used to find the nearest smallest algorithm

# Brute Approach  :
- iterate over an array from 0 to n-1
- to find the nearest smallest we have to search for the left side
from n-1 to 0
- check if(arr[i] >arr[j])
    - nge[i] = arr[j] and break loop
-return nge

time complexity : O(N2)
space complexity : O(N)



#Optimal approach :
- in this we are using the increasing monotonic stack that means when st.top()> new ele then we popped it
- if stack is empty then nge[i] = -1
- st.push(arr[i])
- return nge

time complexity : O(2N)
space complexity : O(N)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> NearestSmallest(vector<int> &arr)
{

    int N = arr.size();
    vector<int> nge(N, -1);

    for (int i = 0; i < N; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if(arr[i] >arr[j]){
                nge[i] = arr[j];
                break;
            }
        }
    }

    return nge;
}

vector<int> NearestSmallest_optimal(vector<int> &arr)
{
    int n = arr.size();
    vector<int> nge(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top() > arr[i])
        {
            st.pop();
        }

        nge[i] = st.empty() ? -1 : st.top();
        st.push(arr[i]);
    }

    return nge;
}

int main()
{
    vector<int> arr = {2, 10, 12, 1, 11};

    vector<int> ans = NearestSmallest(arr);
    for (int num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    vector<int> an = NearestSmallest_optimal(arr);
    for (int num : an)
    {
        cout << num << " ";
    }

    return 0;
}