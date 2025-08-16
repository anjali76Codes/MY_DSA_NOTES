#include<bits/stdc++.h>
using namespace std;

int main()
{

   // taking input first matrix 
    int r1, c1;
    cout<<"Enter first matrix range : ";
    cin>>r1>>c1;

   int  A[r1][c1];

cout<<"Enter 1st matrix elements: ";
   for(int i  = 0 ; i < r1 ; i++){
    for(int j = 0 ; j<c1 ; j++){
        cin>>A[i][j];
    }
   }



// taking input second matrix
    int r2, c2;
    cout<<"Enter second matrix range : ";

    cin>>r2>>c2;

   int  B[r2][c2];

cout<<"Enter 2nd matrix elements : ";

   for(int i  = 0 ; i < r2 ; i++){
    for(int j = 0 ; j<c2 ; j++){
        cin>>B[i][j];
    }
   }


   if(c1!=r2){
    cout<<"Multiplication of this two matrix is not possible";
   }

int C[r1][c2];




/* Explanation
i =0 , A[i][j] = 1 2 
                 3 4

j = 0   B[i][j]= 5 6
                 7 8
value = 0 
k = 0 
0 + 1*5
*/

   for(int i = 0 ; i < r1 ; i++ ){
    for(int j = 0 ; j<c2; j++){
        int value = 0 ; 

        for(int k = 0 ; k< r2; k++){
            value +=A[i][k]*B[k][j];
        }

        C[i][j] = value;
    }
   }


   for(int i = 0 ; i< r1; i++){
    for(int j = 0 ; j< c2; j++){
        cout<<C[i][j]<<" ";
    }
    cout<<endl;
   }
   




return 0;
}
