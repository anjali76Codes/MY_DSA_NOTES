#include<bits/stdc++.h>
using namespace std;
// The Fibonacci sequence is a series of numbers where each number is the sum of the two previous number . It starts with 0 and 1.

int fibonacci( int n ){
    if(n<=1){
        return n;               
    }
    int last = fibonacci(n-1);
    int slast = fibonacci(n-2);
    return last +slast;
}


int main()
{
int n ; 
cin>>n;
cout<<fibonacci(n);

return 0;
}