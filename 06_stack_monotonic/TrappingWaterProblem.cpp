#include<bits/stdc++.h>
using namespace std;

int trappingWater(vector<int>&arr){
    int n = arr.size();
    // x unit =? : min(lmax, rmax)- ht[i]

    // calculate the leftmax , rightmax : prefixMax , suffixMax
    vector<int>lmax(n,0);
    vector<int>rmax(n,0);

    lmax[0] = arr[0];
    rmax[n-1] = arr[n-1];
    int ans = 0;

    // Prefix Sum : compare with previous one i.e i-1
    for(int i = 1; i<n ; i++){
        lmax[i] = max(lmax[i-1] , arr[i] );
    }

  // Suffix Sum  : compare with next ele i.e i+1 
    for(int i =n-2; i>=0 ; i--){
        rmax[i] = max(rmax[i+1] , arr[i] );
    }


    for(int i = 0; i<n ; i++){
        ans += min(lmax[i] , rmax[i])- arr[i];

    }
return ans;
}

int main()
{

    vector<int>arr = {4,2,0,3,2,5};
    cout<<trappingWater(arr);

return 0;
}