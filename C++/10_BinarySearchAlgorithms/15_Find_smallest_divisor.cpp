/*
We are given an arr and we have to find the smallest divisor on oa given threshold


*/

#include <bits/stdc++.h>
using namespace std;

// brute approach - O(max * n)
int smallest_divisor_on_given_threshold(vector<int> &arr, int n, int threshold)
{
    // Get the maximum
    int maxi = *max_element(arr.begin(), arr.end());

    for (int d = 1; d <= maxi; d++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
             sum += ceil((double)arr[j] / d);
        }

        if (sum <= threshold)
        {
            return d;
        }
    }
    return -1;
}


int sumOfD(vector<int> &arr , int n , int div){
    int sum = 0;
    for(int i = 0 ; i < n ; i++){
       sum += ceil((double)arr[i] / div);

}
return sum ;
}


// optimal  - O(log(max) * n)
int smallest_divisor(vector<int>&arr , int n , int threshold){

    // start from 1 to max(arr)
    int low = 1 ;
    int  high = *max_element(arr.begin() , arr.end());
int ans = -1 ;

if(n > threshold ) return -1 ;

    while(low<=high){
        int mid = (low+high)/2 ;


        // mid is - divisor 
        if( sumOfD(arr,n, mid) <=threshold){
            ans = mid ;
            high = mid-1;
        }
        else{
            low = mid+1 ;
        }
    }
    return ans ;
}


int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int threshold;
    cin >> threshold;
    cout << smallest_divisor_on_given_threshold(arr, n, threshold);

    // optimal result
    cout << smallest_divisor(arr, n, threshold);

    return 0;
}