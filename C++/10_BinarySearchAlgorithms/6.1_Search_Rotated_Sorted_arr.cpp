/*
Search the target in rotated sorted array but here array contain duplicates .

*/

#include <bits/stdc++.h>
using namespace std;

bool search(vector<int> &arr, int n, int target)
{

    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
            return true;

        // when low mid and all are equal
        if (arr[low] == arr[mid] && arr[mid] == arr[high])
        {
            low++, high--;
        }

        // when left is sorted
        if (arr[low] <= arr[mid])
        {
            if (target >= arr[low] && target <= arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        // if right is sorted
        else
        {
            if (target >= arr[mid] && target <= arr[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return false;
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

    int target;
    cin >> target;
    cout << search(arr, n, target);

    return 0;
}