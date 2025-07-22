/*
We are given the Histogram
and we have to find the largest rectangle
1. but how can I get the largest rectangle ?
    - By calculating the area of it


#Brute Approach
- First we calculate the nse and pse
- initialize maxi = 0
- traverse the array from  i = 0 to n-1
- keep the track of max and return it
area = w*h
in this my width = nse[i] -pse[i]-1  and height = arr[i]

Time complexity : O(5N)
Space complexity : O(4N)


#Optimal Approach : 
- traverse the array from index 0 to n-1 
- insert first ele in the stack 
- now stack contain the ele so move i to index 1 
- find the pse 
    - if the stack top idx value will be the pse of the current one(ith index) then we push the current ele idx into the stack(no need to compute) 
    - but if not then we pop the idx  and calculate the area to find the largest rectangle 
- In this area = arr[i]*(nse-pse -1) here width and height is index not the ele 
Note* : To calculate the area we require the nse index and pse index so the ele we are popping when top idx value is not the pse of ith ele that means this top idx value will be the nse of the ith ele (nse = i )
and next top idx will be the pse of the ith ele
pse = st.top -> in case of stack is not empty is empty then it is -1 
   
    - repeat the above process until the stack is empty
   
Time complexity : O(2N)
Space complexity : O(N)
*/

#include <bits/stdc++.h>
using namespace std;



vector<int> findNSE(vector<int> arr)
{
    int n = arr.size();
    stack<int> st;
    vector<int> nse(n, -1);

    // Traverse the array from right to left
    for (int i = n - 1; i >= 0; i--)
    {

        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }

        nse[i] = st.empty() ? n : st.top();

        // Push the current element's index onto the stack
        st.push(i);
    }

    return nse;
}

// Function to find the previous smaller element (PSE) for each element in the array
vector<int> findPSE(vector<int> arr)
{
    int n = arr.size();
    stack<int> st;
    vector<int> pse(n, -1);

    // Traverse the array from left to right
    for (int i = 0; i < n; i++)
    {

        while (!st.empty() && arr[st.top()] > arr[i])
        {
            st.pop();
        }

        pse[i] = st.empty() ? -1 : st.top();

        // Push the current element's index onto the stack
        st.push(i);
    }
    return pse;
}

int largest_rectangle(vector<int> arr, int n)
{
    vector<int> nse = findNSE(arr);
    vector<int> pse = findPSE(arr);
    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        // calculate the area - w*h 
        maxArea = max(maxArea, arr[i]* (nse[i] - pse[i] - 1));
    }
    return maxArea;
}





// optimal approach 

int largest_rectangle_optimal(vector<int> arr, int n) {
    stack<int> st;
    int maxArea = 0;

    // Traverse the array
    for (int i = 0; i < n; i++) {
        // When the current element is smaller than the stack top
        while (!st.empty() && arr[st.top()] > arr[i]) {
            int ele = st.top();  // This will return the index
            st.pop();

            int nse = i;  // The current index will be the NSE
            int pse = st.empty() ? -1 : st.top();  // Previous smaller index

            maxArea = max(arr[ele] * (nse - pse - 1), maxArea);
        }
        st.push(i);
    }

    // Process remaining elements in stack
    while (!st.empty()) {
        int ele = st.top();
        st.pop();
        int nse = n;  // Right boundary is the array end
        int pse = st.empty() ? -1 : st.top();

        maxArea = max(arr[ele] * (nse - pse - 1), maxArea);
    }

    return maxArea;
}

int main()
{
    vector<int> arr = {3,2,10,11,5,10,6,3};
    int n = arr.size();
    int ans = largest_rectangle(arr, n);
    cout << ans << endl;
    int res = largest_rectangle_optimal(arr, n);
    cout << res << endl;

    return 0;
}