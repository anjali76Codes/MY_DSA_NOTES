//  Factorial of n number
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int fact= 1;
    for(int i= n ; i>=1; i--){
      fact *=i;   
    } 
    cout<<"The factorial of this "<<n<< " is:"<<fact<<endl;
    return 0;
}





// Power of the number
#include<iostream>
using namespace std;
int main(){
    int  a,b;
    cin>>a>>b;
    int power = 1;
    for(int i=1 ; i<=b; i++){
      power *= a;  
    }
    cout<<a<<" raise to "<<b<<" is:"<<power<<endl;
    return 0 ;

}