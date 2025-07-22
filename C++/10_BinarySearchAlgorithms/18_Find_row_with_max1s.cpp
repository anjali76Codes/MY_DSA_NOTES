/*
find the row which has maximum numbers of ones
Explanation : traverse the matrix as usual using nested loops and for every single row count the number of 1’s.
 Finally, we will return the row with the maximum no. of 1’s. If multiple rows contain the maximum no. of 1’s we will return the row with the minimum index


 # Optimal Approach :
 # role of upper bound:
 
 Key Points:

Matrix Assumption:
The rows of the matrix are sorted (i.e., all 0s appear before 1s in each row).
This property allows us to use binary search to find the first occurrence of 1 quickly.

Optimization:
Instead of iterating through the entire row to count the 1s (O(m) time complexity for each row), we can perform a binary search using lowerBound to find the starting index of 1s in O(log(m)) time.
Once the starting index of 1s is found, the count of 1s in the row is simply m - index, where m is the number of columns.

*/

#include <bits/stdc++.h>
using namespace std;

// brute approach => O(n*m) 
int findRow_with_Max1s(vector<vector<int>> &matrix, int n, int m)
{

    //  - initialized two variable cnt_max = 0 and index = -1

    //  keeps track of the maximum number of 1s encountered in any row
    int cnt_max = 0, index = -1;

    // traverse the matrix
    for (int i = 0; i < n; i++)
    {

        // keeps track of the number of 1s in a specific row
        int cnt_ones = 0;
        for (int j = 0; j < m; j++)
        {
            cnt_ones += matrix[i][j];
        }

        // if the number of 1s in the current row is greater than the max encountered so far , update max and index
        if (cnt_ones > cnt_max)
        {
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;
}



// Optimal approach in this we are optimized the traversal of a row  - O(log(m) * n)


// lower bound - that find the occurrence of the 1s in a row 
int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
       
        if (arr[mid] >= x) {
            ans = mid;
           // moves to left remove the right
            high = mid - 1;
        }
        else {
            // moves to right remove left
            low = mid + 1; 
        }
    }
    return ans;
}


int row_with_max1s(vector<vector<int>> &matrix, int n, int m) {
    int cnt_max = 0;
    int index = -1;

    //traverse the rows:
    for (int i = 0; i < n; i++) {

        // get the number of 1's:
        int cnt_ones = m - lowerBound(matrix[i], m, 1);
        if (cnt_ones > cnt_max) {
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;
}



int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));

    // input values
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout << findRow_with_Max1s(matrix, n, m);
    cout <<row_with_max1s(matrix, n, m);

    return 0;
}
