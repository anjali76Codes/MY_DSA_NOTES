#include<bits/stdc++.h>
using namespace std;

int DigonalSum(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();


    int sum = 0;
    for(int i = 0; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            if(i==j){
                // primary digonal the pattern is : i = j 
                sum += matrix[i][j] ;
            }
        
            // secondary digonal sum is the pattern is :when i goes increasing +1 and j goes decreasing -1  so when i = 2  then j = n -1 -i    (i.e 1)
            else if(j == n-1-i){
                sum+= matrix[i][j];
            }
        }
    }

    return sum;
}

int main()
{

    vector<vector<int>> matrix = {{1, 3, 5}, {10, 11, 10 }, {23 , 30, 34}};

   cout<< DigonalSum(matrix);

return 0;
}