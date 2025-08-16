/*
Search the target in rotated sorted array
variety-1 -> array contains unique elements

We are given the sorted array in rotated form . We need to find the target element in the array.
arr[] = {1, 2, 3 , 4, 5 } -> {4, 5, 1, 2, 3}

1st approach we can use linear search to search the target value

but cause this array is in sorted form and we have to search then  the best we can  use binary search for this , because it reduces the portion that helps to reduce the time complexity O(n) to (logn) .
*/

#include <bits/stdc++.h>
using namespace std;

int Search_in_Rotated_sorted_arr(vector<int>& arr, int n, int target) {
    int low = 0;
    int high = n - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // If mid points to the target
        if (arr[mid] == target) return mid;

        // When the left part is sorted
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= target && target <= arr[mid]) {
                // Element exists in the left part
                high = mid - 1;
            } else {
                // Element does not exist in the left part
                low = mid + 1;
            }
        } else { 
            // If the right part is sorted
            if (arr[mid] <= target && target <= arr[high]) {
                // Element exists in the right part
                low = mid + 1;
            } else {
                // Element does not exist in the right part
                high = mid - 1;
            }
        }
    }
    return -1; // Target not found
}

int main() {
    int n;

    cin >> n;

    vector<int> arr(n);
   
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;

    cin >> target;

    int res = Search_in_Rotated_sorted_arr(arr, n, target);

    if (res == -1) {
        cout << "Element not found in the array." << endl;
    } else {
        cout << "The index is: " << res << endl;
    }

    return 0;
}



