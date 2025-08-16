/*
Peak element
let in array x is peak element when  <x>
arr = { 1, 2, 3, 5, 4 , 8} here 5 is peak ele  and 8 is peak ele

peak ele can be more than one also
*/

#include <bits/stdc++.h>
using namespace std;

// by linear search - O(n)
int peak_ele(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        if ((i == 0 || arr[i] > arr[i - 1]) && (i == n - 1 || arr[i] > arr[i + 1]))
        {
            return arr[i];
        }
    }
    return -1;
}


// using binary search  - O(log n)
int peak_element(vector<int> &arr, int n)
{
    // when only one ele is in array
    if (n == 1)
        return 0;

    // when only two ele is there
    if (arr[0] > arr[1])
        return 0;


    // when in between there is no any peak then the last must be a peak
    if (arr[n - 1] > arr[n - 2])
        return n - 1;

    // initialization
    int low = 1, high = n - 2;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        // if peak ele is greater from left and right as well

        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        {
            return mid;
        }

        // when mid is greater than left we search for peak on right half (i.e eliminate the left half)

        else if (arr[mid] > arr[mid - 1])
        
            low = mid + 1;
        

        // when mid is greater than right we search for peak on left half (i.e eliminate the right half)
        else
        
            high = mid - 1;
        
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

    int ele1 = peak_ele(arr, n);
    int ele2 = peak_element(arr, n);
    if (ele2 != -1)
        cout << ele2;
    else
        cout << "No peak element found";

    return 0;
}
