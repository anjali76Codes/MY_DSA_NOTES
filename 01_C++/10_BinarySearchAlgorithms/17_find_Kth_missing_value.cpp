/*
find kth missing value
arr[] = [2, 3, 4, 7, 11]   k = 5
ans = 9


Brute approach : 
time complexity : O(n)

optimal approach : we can't apply binary directly here binary  use when it comes to find min /max 
so here we fist find the missing and based on that range if my missing < k then remove left half otherwise right half 

time complexity : O(logn)

*/

#include <bits/stdc++.h>
using namespace std;

// brute approach
int find_kth_missing_value(vector<int> &arr, int n, int k)
{

    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= k)
        {
            k++;
        }
        else
        {
            break;
        }
    }
    return k;
}

// optimal approach
int find_kth_missing_value_optimal(vector<int> &arr, int n, int k)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        // find the missing  based on this we can figure out the range that tells us our ans lie between this range so remove the left half by doing low = mid +1
             int missing = arr[mid] - (mid + 1);
        if (missing < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    // arr[high] -> missing but more - how man more required ( so more --> k - missing )
    // ans => arr[high] + more and missing - arr[high] - (high+1)
    // return k + high + 1; cause(low -> high+1)
    return low+k
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
    int k;
    cin >> k;
    cout << find_kth_missing_value(arr, n, k);
    cout << find_kth_missing_value_optimal(arr, n, k);

    return 0;
}