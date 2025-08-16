/*
Lower bound -> smallest index such that arr[ind]>=x
if x = 20 then in this 21 -> lower bound 4 5 19 21 45 

O(n)-> time complexity 
space complexity : O(1)



Upper bound -> smallest index such that arr[ind]>x
*/


#include<bits/stdc++.h>
using namespace std;

int lower_bound_optimal(vector<int>&a , int low , int high , int x){
    int ans = a.size() ;
    while(low<=high){
        int mid = (low+high)/2;
        if(a[mid]>=x){
            ans = mid;
        high = mid-1;
        } 

        else{
            low = mid+1;
        
        }
       
    }
   return  ans ;

}


int upper_bound_optimal(vector<int>&a , int low , int high , int x){
    int ans = a.size() ;
    while(low<=high){
        int mid = (low+high)/2;
        if(a[mid]>x){
            ans = mid;
        high = mid-1;
        } 

        else{
            low = mid+1;
        
        }
       
    }
   return  ans ;

}

int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int x ;
    cin>>x;

    cout<<lower_bound_optimal(a , 0 , n-1 , x)<<endl;

    // in C++ already build-in functions
    int lb = lower_bound(a.begin() , a.end(), x)- a.begin();

 cout<<lb<<endl;
    cout<<upper_bound_optimal(a , 0 , n-1 , x)<<endl;

   

return 0;
}