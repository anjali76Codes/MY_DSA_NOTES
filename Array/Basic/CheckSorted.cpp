#include<bits/stdc++.h>
using namespace std ;

// check array is sorted or not 
bool checkSorted(int arr[] , int n){
  for(int i = 0 ; i<n-1; i++){
    if(arr[i+1] <arr[i]){
      return false ; 
    
    }
  }
  return true;
}

int main(){
  
  int arr[] = {3, 4, 7, 9, 100, 200 , 200000};
  int n = sizeof(arr)/ sizeof(arr[0]);
  
  
  cout<<checkSorted(arr , n)<<" ";
  
  return 0;
  
}