/*
In given rotated array find number of rotations in that given array

*/

/*
We have to find the minimum in rotated sorted array
*/

#include <bits/stdc++.h>
using namespace std;

int count_rotation(vector<int> &arr, int n)
{

    int low = 0, high = n - 1;
    int ans = INT_MAX;
    int index = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        // when only one element is present
        if (arr[low] <= arr[high])
        {
            if (arr[low] < ans)
            {
                ans = arr[low];
            }
            break;
        }

        // when left is sorted
        if (arr[low] <= arr[mid])

        {
            if (arr[low] < ans)
            {
                ans = arr[low];
                index = low;
            }

            low = mid + 1;
        }

        // if right is sorted
        else
        {

            high = mid - 1;
            if (arr[mid] < ans)
            {
                ans = arr[mid];
                index = mid;
            }
        }
    }
    return index;
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

    cout << count_rotation(arr, n);

    return 0;
}