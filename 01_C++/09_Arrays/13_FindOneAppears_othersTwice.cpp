/* Find One appears others twice
 Brute Approach :
 1.Outer loop->  i 0 to n-1  and store in one variable
 2. iterate inner loop 0 to n-1 and check if arr[j] == num
 if yes then increase count by one
 3. at end check if count = 1 then it appears one time only


Better approach :
 using hashing / map :
 1. find the max
 2. assign hash array (i.e max.size()+1) => {0}
 3. iterate the array from 0 to n-1 and hash the array 
 4. and then if hash[arr[i]] == 1 then it is return element that appears one time

 time complexity :O(3n)
 O(n) as we are doing constant time operations in hashing and array iteration
 space complexity : based on the input (max element length)


Optimal approach :
using XOR :
same number - 0 
0^ num - num

*/

#include <bits/stdc++.h>
using namespace std;

int FindOneAppears_othersTwice_brute(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == num)
            {
                cnt++;
            }
        }

        if (cnt == 1)
        {
            return num;
        }
    }
    return -1;
}

int FindOneAppears_othersTwice_better(int arr[], int n)
{
    int maxi = arr[0];
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
    }
    int hash[maxi + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }
    for (int i = 0; i <= maxi; i++)
    {
        if (hash[i] == 1)
        {
            return i;
        }
    }
    return -1;
}


int FindOneAppears_othersTwice_optimal(int arr[] , int n){
    int xor_res = 0;
    for(int i =0 ; i<n; i++){
        xor_res ^= arr[i];
    }
    return xor_res;
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

    // cout << FindOneAppears_othersTwice_brute(arr, n);
    cout << FindOneAppears_othersTwice_better(arr, n);
    cout << FindOneAppears_othersTwice_optimal(arr, n);

    return 0;
}
