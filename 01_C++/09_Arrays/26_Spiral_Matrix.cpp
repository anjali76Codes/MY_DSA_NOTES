/*
Spiral Matrix :
In this order matrix will rotate (i.e spiral form)
Pattern : right -> bottom -> left -> top

Optimal approach :
1. initialize  and create a matrix-> ans[n][m]
    - top = 0 , right = m-1 , left = 0 , bottom = n-1

 while loop -> top<=bottom(to check rows) left<=right(to check columns)
2. 4 cases:
1. for right :
    - for(i = left -> right  i++)
        - a[top][i]
 - top++
 2. for bottom :
    - for(i = top -> bottom i++)
        - a[i][right]
-  right--

3. for left
    - for(i = right -> left i--)
        - a[bottom][i]

- bottom --
4. for top :
    - for(i = bottom -> top)
        a[i][left]
- left++

this step is repeat
5. return the ans 

time complexity : O(n*m)
space complexity : O(n*n)



    */

#include <bits/stdc++.h>
using namespace std;

vector<int> spiral_matrix(vector<vector<int>> &matrix, int n, int m)
{

    // initialization
    // m -> col and n -> row
    int top = 0, right = m - 1, left = 0, bottom = n - 1;

    // dummy matrix
    vector<int>ans ; 

    while (top <= bottom && left <= right)
    {

        // for right
        for (int i = left; i <= right; i++)
        {
            ans.push_back(matrix[top][i]);
        }

        top++;

        // for bottom
        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(matrix[i][right]);
        }

        right--;

        // it checks matrix is still has a row(or top is under the bottom )
        if (top <= bottom)
        {

            // for left
            for (int i = right; i >= left; i--)
            {
                ans.push_back(matrix[bottom][i]);
            }

            bottom--;
        }

        // // it checks matrix is still has a col(or left is under the right )
        if (left <= right)
        {

            // for top
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(matrix[i][left]);
            }
        }
        left++;
    }

    return ans;
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

   vector<int> res =  spiral_matrix(matrix, n, m);


      // Print the spiral order as a 1D array
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}