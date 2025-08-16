/*
Matrix Rotated by 90 degree 
- we are given the n*m matrix and we have to rotate the matrix by 90 degree
- we have to take the first row of the matrix and put it in the last column of the dummy matrix, take the second row of the matrix, and put it in the second last column of the matrix and so. 

# Brute Approach :
By Observation : on left and right j is changing but remains the same and i is constant but from(0 , n-1-i)
-> if we n,m  = 4 then n-1 = 3 (i.e end) when it comes to next put it will occupy second last then third last and so .
1. create a new array(dummy array) of n*m 
2. use two for loops to iterate 
3. do arr[j][n-1-i] = matrix[i][j]
4. return arr;

time complexity : O(n^2)
space complexity : O(n^2)


# Optimal approach :
--> In this instead of using dummy array we are rotating the matrix itself

1.  do the Transpose  of the matrix 
    - in transpose diagonals are always same so no need to change them 
    - we are just swapping the row and column index of the matrix
    pattern found : j is always -> i+1 and 
    i from 0-> n-2 (last is the part of diagonal )
 2.  Reverse each row of the matrix
 3. return the matrix

 space complexity : O(1)

*/


#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> rotated_matrix(vector<vector<int>> &matrix, int n, int m) {
    vector<vector<int>> rotated(m, vector<int>(n, 0)); // Adjust dimensions of the rotated matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            rotated[j][n - 1 - i] = matrix[i][j];
        }
    }
    return rotated;
}


vector<vector<int>> rotated_matrix_optimal(vector<vector<int>> &matrix, int n, int m) {

// O(n/2 * n/2)
for(int i = 0 ; i<n-1 ; i++){
    for(int j = i+1; j<m ; j++){
        // swap (row => col)
        matrix[i][j] = matrix[j][i];
}

}


// O(n * n/2)
// reverse every row to get the result  
for(int i = 0 ; i< n ; i++){
    reverse(matrix[i].begin(), matrix[i].end());
}

return matrix;

}


int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    // vector<vector<int>> rotated = rotated_matrix(matrix, n, m);
    rotated_matrix_optimal(matrix, n, m);

    // for (int i = 0; i < rotated.size(); i++) {
    //     for (int j = 0; j < rotated[0].size(); j++) {
    //         cout << rotated[i][j] << " ";
    //     }
    //     cout << endl; // Adjusted for proper line separation
    // }


  
    // print the matrix 
    for (int i = 0; i <n ; i++) {
        for(int j  = 0 ; j<m ; j++){
            cout << matrix[i][j] << " ";

        }
        cout<<endl;
    }

    return 0;
}
