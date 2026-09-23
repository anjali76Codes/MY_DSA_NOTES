#include <bits/stdc++.h>
using namespace std;

bool sortedArray(int arr[], int n)
{
    // check if sorted or not
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << sortedArray(arr, n);

    return 0;
}