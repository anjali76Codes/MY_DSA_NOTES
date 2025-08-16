/*
We are given an array
- We have to first make the subarray and take the minimum of all subarray and then do the sum of all minimums

#Brute Approach :
- Create a subarray
- find the min of all subarray
- do the sum of all minimums
- return the sum

Time Complexity : O(N2)
Space COmplexity : O(1)

Optimal approach : 
time complexity : O(5N)
space complexity : O(5N)


*Remember : 
- for right side(next)weather it can be smaller or greater --> traverse the array from the last 
- in this stack is decreasing monotonic stack that means if top of stack is >= the current we simply pop it
-if stack is empty or there is no any greater or smaller ele found by default it is -1 


- for left side(previous)weather it can be smaller or greater -->traverse the array from the start 
- in the stack is increasing monotonic stack that means if top of the stack is > than the current we simply pop it .
- in this we are popping the ele when top is greater but it should not be the equal 

*/

#include <bits/stdc++.h>
using namespace std;

int sum_subarray_minimums(vector<int> arr)
{
    int n = arr.size();
    int sum = 0;
    const int mod = 1e9 + 7;
    // traverse the array and creating the subarray
    for (int i = 0; i < n; i++)
    {
        // first ele in all subarray is always a min (cause it is single)
        int mini = arr[i];

        for (int j = i; j < n; j++)
        {
            mini = min(mini, arr[j]);
            sum = (sum + mini) % mod;
        }
    }
    return sum;
}

// Function to find the next smaller element (NSE) for each element in the array
vector<int> findNSE(vector<int> arr)
{
    int n = arr.size();
    stack<int> st;  // Stack to store indices of elements
    vector<int> nse(n, -1);  // Vector to store the next smaller elements, initialized with -1
    
    // traverse the array from the end in case of right side 
    for (int i = n - 1; i >= 0; i--)
    {
        // since this is for right side hence the stack is decreasing monotonic stack which Pop elements from the stack that are greater than or equal to the current element
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }

        // If stack is empty, no smaller element exists, so assign 'n' (out of bounds index)
        // Else, the top of the stack gives the index of the next smaller element
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
    stack<int> st;  // Stack to store indices of elements
    vector<int> pse(n, -1);  // Vector to store the previous smaller elements, initialized with -1
    
    // Traverse the array from left to right
    for (int i = 0; i < n; i++)
    {
        // Pop elements from the stack that are greater than the current element
        while (!st.empty() && arr[st.top()] <= arr[i])
        {
            st.pop();
        }

        // If stack is empty, no smaller element exists to the left, so assign '-1'
        // Else, the top of the stack gives the index of the previous smaller element
        pse[i] = st.empty() ? -1 : st.top();
        
        // Push the current element's index onto the stack
        st.push(i);
    }
    return pse;
}

// Optimal approach to find the sum of minimums of all subarrays in the given array
int sum_minimum_subarray_optimal(vector<int> arr)
{
    int n = arr.size();
    
    // Get the next smaller element (NSE) and previous smaller element (PSE) for each element
    vector<int> nse = findNSE(arr); 
    vector<int> pse = findPSE(arr);

    int total = 0;  // Variable to store the final result
    const int mod = 1e9 + 7;  // To avoid overflow, the result is taken modulo 1e9 + 7

    // Loop through each element of the array
    for (int i = 0; i < n; i++)
    {
        // Calculate the number of subarrays where arr[i] is the minimum element
        int left = i - pse[i];  // Number of subarrays on the left of i
        int right = nse[i] - i; // Number of subarrays on the right of i

        // For each subarray, the current element contributes (left * right * arr[i]) to the sum
        // Add this contribution to the total and take modulo 'mod' to prevent overflow
        total = (total + (right * left * 1LL * arr[i]) % mod) % mod;
    }

    return total;
}

int main()
{
    vector<int> arr = {3, 1, 2, 4};
    int ans = sum_subarray_minimums(arr);
    cout << ans << endl;

        cout << sum_minimum_subarray_optimal(arr) << endl;

    return 0;
}