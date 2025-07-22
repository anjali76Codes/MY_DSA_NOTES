/*
Need to find least capacity to ship packages  within D Days 

-arr contains the weights of the packages
- D is the number of days to ship packages
- capacity is the maximum capacity of the truck
- return the least capacity of the truck to ship all packages in D days
Note* : 
- max of the arr is the least capacity of the ship 
- the ans will always be in the range of max to sum of the weights -> [max , sum]


# Brute approach 
time complexity : O((sum- maxi) +1 * O(n))
*/


#include<bits/stdc++.h>
using namespace std;


int findDays(vector<int>&weights , int n , int c){
    int days = 1 ; 
    int load = 0 ;
    for(int i = 0 ; i < n ; i ++){
       if(load+ weights[i] > c){
        days ++ ;
        load = weights[i];
       }

       else{
        load += weights[i];
       }

}

return days ;
}



// brute approach - linear search
int Least_Capacity(vector<int>&weights , int n , int D){
     
      //Find the maximum and the summation
    int maxi = *max_element(weights.begin(), weights.end());
    int sum = accumulate(weights.begin(), weights.end(), 0);

    for(int i = maxi ; i<sum ; i++){
        if(findDays(weights, n , i) <=D){
            return i; 
        }
    }
    return -1 ;
}




// optimal approach - O((log((sum-maxi)+1) * O(n))
int Least_Capacity_optimal(vector<int>&weights , int n , int D){
     
      //Find the maximum and the summation
    int maxi = *max_element(weights.begin(), weights.end());
    int sum = accumulate(weights.begin(), weights.end(), 0);

   int low = maxi ;
   int high = sum ;

   while(low<= high){
    int mid = (low+high)/2 ;
    if(findDays(weights, n , mid) <= D){
        high = mid - 1 ;
   }
   else{
    low = mid + 1 ;
    }
    }
    return low ;
   
}

int main()
{
    int n;
    cin >> n;
    vector<int>weights(n);
    for(int i = 0; i < n; i++)
    {
        cin >> weights[i];
        }
        int D;
        cin >> D;
        cout<<Least_Capacity(weights, n , D)<<endl;
        cout<<Least_Capacity_optimal(weights, n , D);

return 0;
}
