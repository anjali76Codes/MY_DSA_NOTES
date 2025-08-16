/*
Longest subarray with sum k
subarray it always has contiguous portion
Brute force approach :
1. Generate all possible subarrays of the given array
  steps :- outer loop -> 0 to n-1 and
        - inner loop  i to n-1
        - initialize sum = 0
        - to calculate the sum of the jth element
2.  calculate the sum of its elements
3. If the sum of the subarray is equal to k, then it is a subarray


Time complexity approximately : O(n3) but in best case it is O(n2)



Better Approach :
steps:
1. create hashmap that store prefix sum by iterating i -> 0 to n-1
2. initialize maxLen and sum = 0
2.check  if sum ==k
  - if yes then return maxLen

3. calculate remaining -> sum-k
4. check if it is present in hashmap or not
    - hashmap.find(remaining)!= hashmap.end() then
    - maxLen = max(maxLen, i - hashmap[remaining])
5. also check for sum is present or not
if not then add with its index
6. return maxLen

Note : time complexity : O(n2)




3. optimal approach :
use the two pointer :
1. declare left , right   = 0  , sum = arr[0] , len = 0
2. while loop (right->n)
3. first move (right++) -  calculate the sum of the subarray
4. sum = k update maxLen
5. while loop (left<=right && sum>k)
    - remove first from left (i.e sum+=a[left])
    - move further -> left++
6. return mexLen


Note :
time complexity : Instead of having the complexity O(n2) it is O(2n) because the outer while loop runs for the n--1 but inner loop is not run everytime  it actually  runs n times in total .

space complexity : O(1)

*/

#include <bits/stdc++.h>
using namespace std;

void Longest_subArray_with_sumK_brute(int arr[], int n, int k)
{
    // outer loop
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == k)
            {
                len = max(len, j - i + 1);
            }
        }
    }

    cout << len;
}



// positive -ve , 0 
int Longest_subArray_with_sumK_better(int arr[], int n, long long k)
{

    // 1. map that store prefix sum
    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;

    // 2.iterate across array
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        // 3. check sum is equal to given sum if yes return maxLen
        if (sum == k)
        {
            maxLen = max(maxLen, i + 1);
        }

        // 4. calculate remaining
        int rem = sum - k;
        if (preSumMap.find(rem) != preSumMap.end())
        {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        /*


         at the end store the sum  and its index into the hashmap
         but this is applicable only for positive intergers numbers
         because in case of zero it updates the index of the sum so we got the shortest length  which is not our required so to avoid this :
          In case of  0 or negative numbers we have to check->
            the sum is already present in hashmap or not
            //   preSumMap[sum ] = i;

            */

        // 5 . this checks the presence of the sum
        if (preSumMap.find(sum) == preSumMap.end())
        {
            // when reach to end (i.e not found) add this with its index into hashmap
            preSumMap[sum] = i;
        }
    }

    // 6. return maxLen
    return maxLen;
}



// when only positive and 0 in an array
int Longest_subArray_with_sumK_optimal(int arr[], int n, long long k)
{
    // 1. declaration
    int left = 0;
    int right = 0;
    long long sum = arr[0];
    int maxLen = 0;



    // 2. while loop till end
    while (right < n)
    {

        while (left <= right && sum > k)
        {
            sum = -arr[left];
            left++;
        }

        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }


        // 3. move right and find sum
        right++;
        sum += arr[right];
    }

    return maxLen;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int k;
    cin >> k;
// Longest_subArray_with_sumK_brute(arr, n, k);
    cout << " ";
// cout << Longest_subArray_with_sumK_better(arr, n, k);
    cout << Longest_subArray_with_sumK_optimal(arr, n, k);

    return 0;
}






