/*
Q. to find the largest element in the array

1. Brute force
- we can sort the array and then return the element at the last index of the array

2. Optimal
- we can consider a max element and then compare it with all the elements
- if any of them is greater then max = that element

*/
 


#include<bits/stdc++.h>
using namespace std;

int main() 
{
int n ;
cin>>n;
int arr[n];

for(int i = 0 ; i<n; i++){
    cin>>arr[i];
}


int largest = arr[0];
// iterate from 0 to n-1
for(int i = 0 ; i<n-1 ; i++){
if(arr[i]>largest){
    largest = arr[i];
}
}

cout<<largest;

return 0;
}