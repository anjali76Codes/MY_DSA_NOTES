# include <iostream>
using namespace std ; 


// Largest Elemente in an array


int largestElement(int arr[] , int n){
    // 1. when only one ele is there then it will be my max ele 
   int max = arr[0] ;
 
  // when more than one ele need to traverse and updating the max based on the condition  
   for(int i = 1 ; i<n ; i++){
     if(arr[i]>max){
       max = arr[i] ;
     }
   }
  return max ; 
}


int main (){
  int arr [] = {6, 9, 2, 1 , 10 , 15, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
  
  int res = largestElement(arr,n);
  cout<<res<<" ";
  
  
  return 0 ;
}