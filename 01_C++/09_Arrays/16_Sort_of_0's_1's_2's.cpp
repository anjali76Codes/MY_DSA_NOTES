/* Sort the 0's 1's and 2's
# Brute approach :
1.sort the array

time complexity : for sorting -> it takes O(nlogn)
 space complexity  i.e O(n)


# Better Approach :
1. Count the number of 0's, 1's and 2's
2. use for loop for each of the count first to store 0's and then 1's and then 2's

time complexity : O(2n)
space complexity : O(1)


# Optimal approach :
using Dutch National flag Algorithm:
1. Initialize three pointers low, mid, high
2. low = 0, mid = 0, high = n-1
3. while mid <= high
if arr[mid] == 0
    - swap(arr[low], arr[mid]) do low++ and mid++
 if arr[mid] == 1  do
    - mid++
 if arr[mid] == 2
    - swap(arr[mid], arr[high]) do high--

Note : 
time complexity : O(n)
space complexity : O(1)

*/

#include <bits/stdc++.h>
using namespace std;

void Sort_0_1_2_brute(int arr[], int n)
{
    sort(arr, arr + n);
}

void Sort_0_1_2_better(int arr[], int n)
{
    int count0 = 0, count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            count0++;
        }
        else if (arr[i] == 1)
        {
            count1++;
        }
        else
        {
            count2++;
        }
    }

    for (int i = 0; i < count0; i++)
    {
        arr[i] = 0;
    }
    for (int i = count0; i < count0 + count1; i++)
    {
        arr[i] = 1;
    }
    for (int i = count0 + count1; i < n; i++)
    {
        arr[i] = 2;
    }
}

void Sort_0_1_2_optimal(int arr[], int n)
{
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
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

    // Sort_0_1_2_brute(arr, n);
    // Sort_0_1_2_better(arr, n);
    Sort_0_1_2_optimal(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}