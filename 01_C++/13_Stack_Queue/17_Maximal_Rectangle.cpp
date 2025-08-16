/*
We have to find the largest Rectangle which carry the no of ones
in the binary representation of the given number.

steps :
- create 2d array pass
- initialize the area = 0 & prefix sum array
- in this to get the prefix sum
    - we are traversing the array column wise
    - j from 0 to n-1 -> outer loop (col)
    initialize sum = 0
    - inner loop from i = 0 to n-1 (row)
    sum += matrix[i][j]
- if mat[i][j] == 0 then sum again initialize to 0
 if not then store the sum into the prefix sum array
 - now traverse the prefix sum through rows and track the max area that contains the no of ones


 time complexity : O(n*m)+O(n*2m)
 space complexity : O(n*m)+O(n)
*/

#include <bits/stdc++.h>
using namespace std;

// Optimal approach
int largest_rectangle(vector<int> arr, int n)
{
    stack<int> st;
    int maxArea = 0;

    // Traverse the array
    for (int i = 0; i < n; i++)
    {
        // When the current element is smaller than the stack top
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            int ele = st.top(); // This will return the index
            st.pop();

            int nse = i;                          // The current index will be the NSE
            int pse = st.empty() ? -1 : st.top(); // Previous smaller index

            maxArea = max(arr[ele] * (nse - pse - 1), maxArea);
        }
        st.push(i);
    }

    // Process remaining elements in stack
    while (!st.empty())
    {
        int ele = st.top();
        st.pop();
        int nse = n; // Right boundary is the array end
        int pse = st.empty() ? -1 : st.top();

        maxArea = max(arr[ele] * (nse - pse - 1), maxArea);
    }

    return maxArea;
}

int max_rectangle(int matrix[][5], int r, int c)
{
    int max_area = 0;
    vector<vector<int>> prefix_sum(r, vector<int>(c, 0));

    // Traverse column-wise
    for (int j = 0; j < c; j++)
    {
        int sum = 0;
        for (int i = 0; i < r; i++)
        {
            // Calculate the sum
            sum += matrix[i][j];
            // When 0 is encountered again, initialize sum = 0
            if (matrix[i][j] == 0)
                sum = 0;
            prefix_sum[i][j] = sum;
        }
    }

    // Now traversing the prefix sum array
    for (int i = 0; i < r; i++)
    {
        max_area = max(max_area, largest_rectangle(prefix_sum[i], c));
    }

    return max_area;
}

int main()
{
    // Create a 2D matrix
    int matrix[5][5] = {
        {1, 0, 1, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 1}};

    int ans = max_rectangle(matrix, 5, 5);
    cout << "Maximum area of rectangle is " << ans << endl;

    return 0;
}
