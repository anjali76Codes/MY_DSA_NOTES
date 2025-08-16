/*
First and last occurrence in given array

Time Complexity: O(log n)

Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int First_Occurrence(vector<int> &a, int n, int x)
{
    int low = 0, high = n - 1;
    int first = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] == x)
        {
            first = mid;
            high = mid - 1;
        }
        else if (a[mid] > x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return first;
}


int Last_Occurrence(vector<int> &a, int n, int x)
{
    int low = 0, high = n - 1;
    int last = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] == x)
        {
            last = mid;
           low = mid+1 ;
        }
        else if (a[mid] > x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return last;
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

    int x;
    cin >> x;

    cout << First_Occurrence(a, n, x)<<endl;
    cout << Last_Occurrence(a, n, x);

    return 0;
}