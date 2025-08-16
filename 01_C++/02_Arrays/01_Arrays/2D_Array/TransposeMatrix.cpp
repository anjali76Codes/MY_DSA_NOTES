#include<bits/stdc++.h>
using namespace std;

int main()
{

   // taking input first matrix 
    int r, c;
    cout<<"Enter first matrix range : ";
    cin>>r>>c;

   int  A[r][c];

cout<<"Enter 1st matrix elements: ";
   for(int i  = 0 ; i < r ; i++){
    for(int j = 0 ; j<c ; j++){
        cin>>A[i][j];
    }
   }


cout <<"Real Matrix: "<<endl;
for(int i = 0 ; i < r ; i++){
    for(int j = 0 ; j<c ; j++){
     cout<<A[i][j]<<" ";
    }
    cout<<endl;
}


cout <<"Transpose Matrix: "<<endl;
for(int i = 0 ; i < r ; i++){
    for(int j = 0 ; j<c ; j++){
     cout<<A[j][i]<<" ";
    }
     cout<<endl;
}



return 0 ;
}