/*
# Next Permutation
Brute  Approach :
1. Generate all permutations (rearrangement) in sorted order
2. Linear Search
3. Next Permutation (where match then return next)


Note : Brute approach is not suitable for this because it take more time to execute which ie not required
Time complexity : O(n!)+O(n) so if we have n = 15 then 15! is -> 10^12 that's take huge amount of time to execute

 
Better approach : we can do this using stl

Optimal Approach :
steps :
1. Longer Prefix match
    - a[i] < a[i+1]

2. find > breaking point but the smallest one so that you stay close

3. Try to place remaining in sorted order .

time complexity in worst case : O(3n)
space complexity : O(1)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> next_permutation(vector<int> &arr, int n)
{

    int index = -1;

    //1.  to get longer prefix match
    for (int i = n - 2; i >= 0 ; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            index = i;
            break;
        }
    }

    //2.  if there is no any break index then given one is  the last (so reverse from begin to end )
    if (index == -1)
    {
        reverse(arr.begin(), arr.end());
        return arr;
    }


    //3. if there is break index then from back we have to find least greater 

    for(int i = n-1 ; i>index ; i--){
        if(arr[i] > arr[index]){
            swap(arr[i] , arr[index]);
            break ; 
        }
    }

// 4. after swapping we need to sort the remaining elements starting from the index at index+1 (next of the break index ) till end 
    reverse(arr.begin() + index + 1  , arr.end());

    return arr;
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

  vector<int>res =   next_permutation(arr, n);
    for(auto it : res){
        cout<<it<<endl;
    }

    return 0;
}