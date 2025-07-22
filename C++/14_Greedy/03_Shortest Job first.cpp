/*
Shorted job first : selects the waiting process with smallest execution time to execute first


#Optimal Approach : 
- sort the array 
- calculate the waiting time and time at which execution will ends 


Time complexity : O(N)+O(NlogN)
Space complexity : O(1)

*/


#include<bits/stdc++.h>
using namespace std;

int ShortestJobFirst(int arr [] , int n ){
  
sort(arr, arr+n);
    int wt = 0 , t = 0 ; 
    for(int i = 0 ; i< n ; i++){
        wt += t;
        t +=arr[i];
    }

    return (wt/n);

}

int main()
{

    int n ; 
    cin>> n ; 
    int arr[n]= {1, 3, 7, 2, 5};

    cout<<ShortestJobFirst(arr,n);

return 0;
}