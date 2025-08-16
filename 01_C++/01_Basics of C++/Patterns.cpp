//1. Rectangular Shape


#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 1; i<=n; i++){
        for(int j= 1; j<=m; j++){
            if(i==1 || j==1 || i==n || j==m){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}




// 1. Triangular Shape
#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 1; i<=n; i++){
        for(int j= 1; j<=i; j++){
          cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}





// 1. Triangular Shape (Decrement Type)
#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    for(int i = n; i>=1; i--){
        for(int j= 1; j<=i; j++){
          cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}




// Triangle shape
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++){
        for(int j= 1; j<=(n-i); j++){
          cout<<" ";
        }
      for(int j =1; j<=(2*i-1); j++){
        cout<<"*";
      }
      cout<<endl;
    }
    return 0;
}









