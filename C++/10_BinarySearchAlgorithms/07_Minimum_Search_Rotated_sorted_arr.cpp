/*
We have to find the minimum in rotated sorted array 
*/

#include <bits/stdc++.h>
using namespace std;

int minimum_search(vector<int> &arr, int n)
{

    int low = 0, high = n - 1;
    int ans = INT_MAX ;
    while (low <= high)
    {
        int mid = (low + high) / 2;
    

// when only one element is present
if(arr[low]<=high){
    
}
        // when left is sorted
        if (arr[low] <= arr[mid])
        {
        ans = min(ans, arr[low]);
         low = mid+1;
        }

        // if right is sorted
        else
        {
           ans = min(ans , arr[mid]);
           high = mid - 1 ;
        }
    }
    return ans;
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

   
    cout << minimum_search(arr, n);

    return 0;
}