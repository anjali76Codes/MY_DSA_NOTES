# include <iostream>
using namespace std ; 


// Largest Elemente in an array
int largestElement(int arr[] , int n){
   int max = arr[0] ;
   int smax = -1 ;
 
   
   for(int i = 1 ; i<n ; i++){
     if(arr[i]>max){
       smax = max ;
       max = arr[i] ;
     }
   // 2nd largest can be right side as well so even at middle max ele is come then also there is chances to come smax after this so for that we have to check current ele with smax as well  
    else if(arr[i]>smax && smax != max){
      smax = arr[i];
    }
   }
  return smax; ; 
}


int main (){
  int arr [] = {6, 9, 2, 100 , 10 , 15, 3000};
    int n = sizeof(arr) / sizeof(arr[0]);
  
  int res = largestElement(arr,n);
  cout<<res<<" ";
  
  
  return 0 ;
}