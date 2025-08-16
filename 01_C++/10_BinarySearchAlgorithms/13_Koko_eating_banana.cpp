/*
Problem Statement: A monkey is given ‘n’ piles of bananas, whereas the 'ith' pile has ‘a[i]’ bananas. An integer ‘h’ is also given, which denotes the time (in hours) for all the bananas to be eaten.

Each hour, the monkey chooses a non-empty pile of bananas and eats ‘k’ bananas. If the pile contains less than ‘k’ bananas, then the monkey consumes all the bananas and won’t eat any more bananas in that hour.

===============
#Find the minimum number of bananas ‘k’ to eat per hour so that the monkey can eat all the bananas within ‘h’ hours.


time complexity for brute approach :
 O(max(a[]) * N)


time complexity for optimal approach :
 O(N * log(max(a[]))),

 space complexity : O(1)
*/

#include<bits/stdc++.h>
using namespace std;


// calculate the max of the array 
int findMax(vector<int> &v) {
    int maxi = INT_MIN;
    int n = v.size();
    //find the maximum:
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}

// return the min integer k (that is within the h time limit)
int calculateTotalHours(vector<int> &v,int n , int hourly) {
    int totalH = 0;
    //find total hours:
    for (int i = 0; i < n; i++) {
        totalH += ceil((double)(v[i]) / (double)(hourly));
    }
    return totalH;
}

// brute approach 
int minimumRateToEatBananas(vector<int> v,int n , int h) {
    //Find the maximum number:
    int maxi = findMax(v);

    //Find the minimum value of k:
    for (int i = 1; i <= maxi; i++) {
        int reqTime = calculateTotalHours(v,n, i);
        if (reqTime <= h) {
            return i;
        }
    }

    //dummy return statement
    return maxi;
}


// optimal approach - binary search 
int minimumRateToEatBananas_optimal(vector<int> v, int n , int h) {
    int low = 1, high = findMax(v);

    //apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        int totalH = calculateTotalHours(v,n, mid);
        if (totalH <= h) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
}


int main()
{
    int  n ;
    cin>>n ;
    vector<int>arr(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin>>arr[i] ;
        }

        int h ; 
        cin>>h ;
      int ans = minimumRateToEatBananas(arr , n , h);
      int ans1 = minimumRateToEatBananas_optimal(arr , n , h);
        cout << "Koko should eat atleast " << ans << " bananas/hr.\n";
        cout << "Koko should eat atleast " << ans1 << " bananas/hr.\n";

return 0;
}