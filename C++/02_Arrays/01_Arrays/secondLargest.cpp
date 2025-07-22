#include<bits/stdc++.h>
using namespace std;

 int largestElementIndex( int arr[] , int size ){
    int max = INT_MIN ;
    int maxIndex  = 0 ;

    for(int i = 0 ; i < size ; i++){
        if(arr[i]> max ){
            max = arr[i];
            maxIndex = i;
        }
    }

    return maxIndex;
 }





int main()
{

int arr [] = {2,5,6,7,9,4,8};

int indexOfLargest = largestElementIndex(arr , 7);
arr[indexOfLargest] = -1;

int secondLargestIndex = largestElementIndex(arr , 7);
// cout <<arr[secondLargestIndex]<<endl;

arr[secondLargestIndex] = -1;

int thirdLargestIndex =  largestElementIndex(arr , 7);
cout<<arr[thirdLargestIndex]<<endl;

return 0;
 


}






