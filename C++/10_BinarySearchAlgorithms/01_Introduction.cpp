/*
Binary Search :
Binary search is an only applicable for Whenever we are performing a search in sorted area .
# Iterative Code :
1. start iterating  from low to high
2. calculate mid = (low+high)/2
3. if arr[mid] == target retrun mid ;
4. if target > arr[mid] then low = mid+1
5. if target < arr[mid] then high = mid-1
6. repeat step 1-5 until low > high

# Recursive Code
1. Base condition
    - if(low>= high)   return -1

2.calculate mid
3. if arr[mid] == target then return mid
4. if target > arr[mid] then call
    - function (arr, mid+1 , high , target)
5. if target < arr[mid] then call
     function(arr , low , mid-1 , target)


Time complexity : O(log2N) (if we have 32 ele  in an array , then approx 5 or 6 steps(2^5-> 32) we required to search )
Space complexity : O(1)
Overflow case : to avoid this mid = low+ (high-low)/2


*/

#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &nums, int target)
{
    int n = nums.size(); // size of the array
    int low = 0, high = n - 1;

    // Perform the steps:
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
            return mid;
        else if (target > nums[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int binarySearch_Recursive(vector<int> &a , int low , int high , int target)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (a[mid] == target)
    return mid;

    else if (target > a[mid])
        return binarySearch_Recursive(a, mid + 1, high, target);
    else
        return binarySearch_Recursive(a, low, mid - 1, target);
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int target;
    cin >> target;
    int ind = binarySearch(a, target);
    if (ind == -1)
        cout << "The target is not present." << endl;
    else
        cout << "The target is at index: "
             << ind << endl;

    cout << binarySearch_Recursive(a, 0, n - 1, target);
    return 0;
}
