/*
# Set matrix zero
    We are given the matrix n*m that contains only 1 and 0 as an elements
# Brute Approach :
1. two for loops - to iterate on n*m matrix (i-> row  and col-> j )
2. if matrix[i][j] == 0
    - call function Marks Row(i)
    - call functions Marks Col(j)
3. Marks Row(i)
    - for loop to iterate on col(j(0-> m))
    - if  matrix[i][j] = 0 marks matrix[i][j] = -1
4. Marks Col(j)
    - for loop to iterate on row(i(0-> n))
    - if  matrix[i][j] = 0   marks matrix[i][j] = -1
5. who are the -1 mark them 0 by iterating on matrix

time complexity : O(n*m)*O(n+m)*O(n*m)=> approximately O(n^3)



# Better Approach :
1.create one more col and row(one extra row and col)  in equal size of m n respectively  and assign 0 to them
2. iterate(2 loops) on matrix and if matrix[i][j] = 0 then assign
    - Row[i] = 1
    - Col[j] = 1
3. Iterate (2 loops) and  Check condition
    - if (Row[i] ==1 || Col[j] ==1)
    - marks entire row and col = 0 (matrix[i][j] = 0)
4. return matrix

time complexity  : O(n*m) + O(n*m) -> O(2*n*m)
space complexity : O(n)+O(m)



# Optimal Approach :
1.Use the first row and first column to mark which rows and columns should be zeroed.
2. Iterate through the matrix, and if matrix[i][j] == 0, 
    set  i-th row(j constant)    ->matrix[i][0] = 0 
   - and set j-th col (i constant)  
   - if(j!= 0) then    ->  matrix[0][j] = 0.
    - else colo = 0 



 
3. Iterate through the matrix (starting from matrix[1][1]), and if matrix[i][0] == 0 || matrix[0][j] == 0, set matrix[i][j] = 0.
4. Zero the first row if matrix[0][0] == 0.
5. Zero the first column if col0 == 0.
6. Return the updated matrix.


time complexity : O(2*n*m)
but space complexity : O(1)  -> col0 = 1(flag )





*/

#include <bits/stdc++.h>
using namespace std;
void markRow(vector<vector<int>> &matrix, int n, int m, int i)
{
    // set all non-zero elements as -1 in the row i:
    for (int j = 0; j < m; j++)
    {
        if (matrix[i][j] != 0)
        {
            matrix[i][j] = -1;
        }
    }
}

void markCol(vector<vector<int>> &matrix, int n, int m, int j)
{
    // set all non-zero elements as -1 in the col j:
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][j] != 0)
        {
            matrix[i][j] = -1;
        }
    }
}

void set_matrix_zero_brute(vector<vector<int>> &matrix, int n, int m)
{
    // Set -1 for rows and cols
    // that contains 0. Don't mark any 0 as -1:

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                markRow(matrix, n, m, i);
                markCol(matrix, n, m, j);
            }
        }
    }

    // Iterating on the matrix and marking -1 elements to 0
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

vector<vector<int>> set_matrix_zero_better(vector<vector<int>> &matrix, int n, int m)
{

    // create one more col and row with in equal size of m n respectively  and assign 0 to them
    int Col[m] = {0};
    int Row[n] = {0};

    // mark the col and row which contains zero
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                Row[i] = 1;
                Col[j] = 1;
            }
        }
    }

    /* The code snippet you provided is part of the `set_matrix_zero_better` function. In this section
    of the code: */
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            /* This logic ensures that if any row or column contains a zero, the entire row and column are marked as zeros
            in the matrix. */
            if (Row[i] == 1 || Col[j] == 1)
            {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}

vector<vector<int>> set_matrix_zero_optimal(vector<vector<int>> &matrix, int n, int m)
{


// col and row (inside matrix)
    //   int Col[m] = {0}; --> matrix[0][..];
    // int Row[n] = {0}; -->    matrix[..][0];
   
   

   // Initialize a col to track if the first column should be zeroed
    int col0 = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                // mark i-th row
                matrix[i][0] = 0;

                // mark j-th col

                if (j != 0)
                {
                    matrix[0][j] = 0;
                }
                else
                {
                    col0 = 0;
                }
            }
        }
    }

    // to convert all the ones to zeroes who're marked  but without considering first row and col.
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }


 //  Zero the first row if matrix[0][0] == 0. 
    if(matrix[0][0] == 0){
        for(int j = 0 ; j< m ; j++){
            matrix[0][j] = 0;
        }
    }


    // Zero the first column if col0 == 0.
if(col0 == 0){
    for(int i = 0 ; i< n ; i++){
        matrix[i][0] = 0;
        }
}

    return matrix;
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

    // set_matrix_zero_brute(matrix, n, m);
    // set_matrix_zero_better(matrix, n, m);
    set_matrix_zero_optimal(matrix, n, m);

    // Print the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
