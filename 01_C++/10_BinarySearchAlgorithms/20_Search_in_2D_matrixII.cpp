/*
Search in 2D matrix part 2
in this we don't have all sorted elements we only have the all rows and columns are sorted and we are ask to return the index(rwo ,col)

#Brute Approach :


#Better approach : 
- In this approach we are traversing on a row 
- As row is sorted we are using the binary search by considering the row as 1D array 
- if target found return the ith row and index(i, index)


#Optimal approach :
- start from the top-last corner or bottom-start corner (where we have the pattern :  row / col  one is in increasing and so another is decreasing  pattern )

- if ele == target return {row,col}
- if less then the do row++; 
- if greater then do col--;


*/

#include <bits/stdc++.h>
using namespace std;

// brute approach : ==> : O(n*m)
pair<int,int> Search_matrix_brute(vector<vector<int>>& matrix, int n ,int m ,int target) {

    //traverse the matrix:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == target)
            return {i,j};
        }
    }
    return {-1 ,-1};
}




// better approach : ==>  O(n*logm)

int binarySearch(vector<int> &matrix, int m, int target)
{
    int low = 0, high = m - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (matrix[mid] == target)
            return mid;

        else if (matrix[mid] < target)
            low = mid + 1;

        else
            high = mid - 1;
    }
    return -1;
}

pair<int, int> Search_matrix_better(vector<vector<int>> &matrix, int n, int m, int target)
{
    int index ;
    // traverse on a row
    for (int i = 0; i < n; i++)
    {

          // Apply binary search on the current row
        index = binarySearch(matrix[i], m, target);

            if (index != -1)
        {
            return {i, index};
        }
    }

    return {-1, -1};
}




// optimal approach : => O(n+m)
pair<int, int> Search_matrix_optimal(vector<vector<int>> &matrix, int n, int m, int target)
{
    int row = 0;
    int col = m - 1;

    while (row < n && col >= 0)
    {
        if (matrix[row][col] == target)
        {
            return {row, col};
        }

        else if (matrix[row][col] < target)
        {
            row++;
        }

        else
        {
            col--;
        }
    }
    return {-1, -1};
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int target;
    cin >> target;

    //   pair<int, int> res = Search_matrix_brute(matrix, n, m, target);

    // pair<int, int> res = Search_matrix_better(matrix, n, m, target);
    pair<int, int> res = Search_matrix_optimal(matrix, n, m, target);

    cout << res.first << "," << res.second << endl;
    return 0;
}