/* Consecutive Ones
Brute approach :
- Iterate through the array and count the number of consecutive ones.
- And increase the the max and count 
- if break then do count = 0 
- at end return max
time complexity : O(n)

*/



#include <bits/stdc++.h>
using namespace std;

int Consecutive_Ones(int arr[], int n)
{
    int maxi = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            cnt++;
            maxi = max(maxi, cnt);
        }
        else
        {
            cnt = 0;
        }
    }

    return maxi;
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

    cout << Consecutive_Ones(arr, n);

    return 0;
}