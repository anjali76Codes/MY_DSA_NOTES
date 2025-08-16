/*
Find single element in sorted array where all elements repeated twice but one ele is once
*/

#include <bits/stdc++.h>
using namespace std;
int find_single_ele(vector<int> &arr, int n)
{

    if (n == 0)
        return arr[0];

    // it reduces most of the conditions
    if (arr[0] != arr[1])
        return arr[0];
    if (arr[n - 1] != arr[n - 2])
        return arr[n - 1];

    // initialization
    int low = 1, high = n - 2;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        // when left and right half is not matching to the mid ele  that means at this index we got our single ele
        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1])
        {
            return arr[mid];
        }

        // if left half is not matching to mid ele that means single ele is in right half (eliminate left half)

        if (mid % 2 == 0 && arr[mid + 1] == arr[mid] || mid % 2 == 1 && arr[mid - 1] == arr[mid])
        {
            low = mid + 1;
        }

        else
        {
            high = mid - 1;
        }
    }

    return -1;
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

    int ele = find_single_ele(arr, n);
    if (ele != -1)
        cout << ele;
    else
        cout << "No single element found";

    return 0;
}
