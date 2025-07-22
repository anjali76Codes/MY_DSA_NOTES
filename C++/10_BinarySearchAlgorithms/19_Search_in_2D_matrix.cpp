/*
Search the target in a 2D matrix (which are given in sorted form )

# Better approach :
- each row in the given matrix is sorted.
- so instead of doing the search col by col it determine the specific row 
- In better approach we first find a row in that our target which lies in between 
- once a row is found by applying binary seach we search for the target within that range

If the target lies between the first and last element of the row (i.e. matrix[i][0] <= target && target <= matrix[i][m-1]), we can conclude that the target might be present in that specific row.




optimal approach :
time complexity : O(log(n*m))
*/

#include <bits/stdc++.h>
using namespace std;

// brute approach ->  O(n*m)
bool Search_target_brute(vector<vector<int>> &matrix, int n, int m, int target)
{

    // traverse the matrix:
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == target)
                return true;
        }
    }
    return false;
}




// better approach ==>  O(n + logm)

bool binarySearch(vector<int> &matrix, int n, int target)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (matrix[mid] == target)
            return true;
        else if (matrix[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

bool Search_target_better(vector<vector<int>> &matrix, int n, int m, int target)
{

    for (int i = 0; i < n; i++)
    {
        // check for the range from start to end
        if (matrix[i][0] <= target && target <= matrix[i][m - 1])
        {

            // here we are applying the binary search bys sending 2d matrix as an array (1D)
            return binarySearch(matrix[i], n,  target);
        }
    }
    return false;
}



// optimal approach
bool Search_target_optimal(vector<vector<int>> &matrix, int n, int m, int target)
{
    int low = 0;
    int high = (n * m - 1);

    while (low <= high)
    {
        int mid = (low + high) / 2;
        
        // when we are considering this 2d into 1D then we need the (row , col)
        int row = mid / m;
        int col = mid % m;

        if (matrix[row][col] == target)
        {
            return true;
        }

        else if (matrix[row][col] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return false;
}

int main()
{
    int n, m;
    cin >> n;
    cin >> m;
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

    if (Search_target_brute(matrix, n, m, target))
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }

    cout << Search_target_better(matrix, n, m, target)<<endl;
    cout << Search_target_optimal(matrix, n, m, target);

    return 0;
}