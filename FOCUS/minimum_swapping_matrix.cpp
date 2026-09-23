/*
You have to place the maximum element at the centre of the matrix in minimum swapping.
Swapping is only possible for adjacent rows or columns.
*/


#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;  // Read the size of the matrix (n x n)
    
    vector<vector<int>> matrix(n, vector<int>(n));
    int max_val = -1, max_row = -1, max_col = -1;
    
    // Input the matrix and find the maximum element's position
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
            if(matrix[i][j] > max_val) {
                max_val = matrix[i][j];
                max_row = i;
                max_col = j;
            }
        }
    }

    // The center of the matrix
    int center_row = n / 2;
    int center_col = n / 2;
    
    // Calculate the number of swaps needed to move the maximum element to the center
    int row_swaps = abs(max_row - center_row);
    int col_swaps = abs(max_col - center_col);
    
    // Total swaps is the sum of row and column swaps
    int total_swaps = row_swaps + col_swaps;
    
    // Output the result
    cout << "Minimum swaps required: " << total_swaps << endl;

    return 0;
}
