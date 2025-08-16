/*
We are given an array we have find the ranges sum 
ranges = largest-smallest 
we have to find for each subarray largest and smallest and after finding the ranges of subarray return the sum 

#Brute Approach : 
- traverse the entire array from i= 0 to n-1 
- take next ele and make the subarray one by one (i.e from j= i+1 to n-1)
- after outer loop first ele is largest as well as smallest in each subarray grps
- do (largest - smallest) and get the sum of all at the end 
- return sum 


Time complexity : O(N2)
space complexity : O(1)


#Optimal approach : 
- find the sum of subarray minimums and similarly find the sum of subarray maximums 
- subtract it  
- return the sum 


Time complexity : O(10N)
space complexity : O(10N)
*/

#include<bits/stdc++.h>
using namespace std;

int find_sum_subarray_ranges(vector<int>arr , int n){
    int sum = 0 ; 
    for(int i = 0 ; i<n; i++){
        int largest = arr[i], smallest = arr[i];
        for(int j = i+1 ; j<n ; j++){
            largest = max(largest, arr[j]);
            smallest = min(smallest, arr[j]);
            sum += (largest - smallest);
        }
    }
    return sum ;
}



vector<int> findNSE(vector<int> arr)
{
    int n = arr.size();
    stack<int> st;  // Stack to store indices of elements
    vector<int> nse(n, -1);  // Vector to store the next smaller elements, initialized with -1
    
    // start traversing from the end side in case of right side 
    for (int i = n - 1; i >= 0; i--)
    {
        // since it is next smaller ele then stack should be Pop elements from the stack that are greater than or equal to the current element
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
        while (!st.empty() && arr[st.top()] > arr[i])
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
int sum_minimum_subarray(vector<int> arr)
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


vector<int> find_nse(vector<int> arr)
{
    int n = arr.size();
    stack<int> st;  // Stack to store indices of elements
    vector<int> nse(n, -1);  // Vector to store the next smaller elements, initialized with -1
    
    // Traverse the array from right to left
    for (int i = n - 1; i >= 0; i--)
    {
        // Pop elements from the stack that are greater than or equal to the current element
        while (!st.empty() && arr[st.top()] < arr[i])
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
vector<int> find_pse(vector<int> arr)
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




int sum_maximum_subarray(vector<int> arr)
{
    int n = arr.size();
    
    // Get the next smaller element (NSE) and previous smaller element (PSE) for each element
    vector<int> nse = find_nse(arr); 
    vector<int> pse = find_pse(arr);

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





int sum_subarray_ranges_optimal(vector<int>arr  ){
return sum_maximum_subarray(arr)- sum_minimum_subarray(arr);
}

int main()
{

    vector<int> arr= {1, 4, 3, 2};
    int n = arr.size();
    int ans = find_sum_subarray_ranges(arr,n);
    cout<<ans<<endl;

    int res = sum_subarray_ranges_optimal(arr);
    cout<<res<<endl;

return 0;
}