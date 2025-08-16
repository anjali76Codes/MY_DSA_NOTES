#include <bits/stdc++.h>
using namespace std;


bool searchInMatrix(vector<vector<int>>matrix , int target){
     int n = matrix.size();
    int m = matrix[0].size();
   
    // hpypthetically consider 2d array in 1d array
    // as matrix is sorted apply binary search

    int low = 0 ;
    int high = (n*m)-1;

    while(low<=high){
        int mid = (low+high)/2;
        int row = mid/m ;  // return the index of the row 
        int col = mid%m ;  // return the index of the col 

        if(matrix[row][col] == target){
            return true ;
        }

        else if(matrix[row][col]<target){
            low = mid+1 ;
        }

        else{
            high = mid-1 ;
        }
        
    }

    return false;

}

int main()
{

    vector<vector<int>> matrix = {{1, 3, 5, 7},
                                  {10, 11, 16, 20},
                                  {23, 30, 34, 60}};
    
    int target = 3;
   cout<< searchInMatrix(matrix , target);


    return 0;
}