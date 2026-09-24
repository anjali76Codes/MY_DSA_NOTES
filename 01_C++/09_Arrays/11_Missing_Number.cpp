/* Find missing number from the array at given N
Brute Approach :
1. Iterate i from 1 to n (outer loop)
2. inner loop - that check if ith index number is present in the array or not
    - if yes then set flag = 1 and break
3. at end if flag == 0 then it return i index value (i.e missing number)

4. time complexity : O(n*n)
5. space complexity : O(1)


Better approach :
1. by using hashing
2. create hash array n+1 size and initially assign each index value -> 0
3. iterate through array and hash array
4. if element found marked as 1
5. at end check hash[i] == 0 then return i -> (missing number)

time complexity : O(N)+O(N) -> O(2N) -> O(N)
space complexity : O(N)


Optimal approach:
1. sum of first n natural number = n*(n+1)/2
2. iterate i from 0 to n-1 and find the sum of the array
3. return sum of first n natural number - sum of all element in array

time complexity : O(N)
space complexity : O(1)

pro optimal approach :
Use XOR :
1. XOR of first n natural number = n ( in XOR same value -> return 0  and if one zero and any number -> that number)
2. XOR of the array ( all zero except that one is missing )

XOR is best because size can exceed in case of optimal approach but in case of XOR the size can  never be exhausted


*/

#include <bits/stdc++.h>
using namespace std;

int Missing_Number_brute(int arr[], int N)
{

    for (int i = 1; i <= N; i++)
    {
        int flag = 0;
        for (int j = 0; j < N - 1; j++)
        {
            if (arr[j] == i)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            return i;
        }
    }
}

// better approach
int Missing_Number_better(int arr[], int N)
{
    int hash[N + 1] = {0};
    for (int i = 1; i <= N; i++)
    {
        hash[arr[i]] = 1;
    }
    for (int i = 1; i < N; i++)
    {
        if (hash[i] == 0)
        {
            return i;
        }
    }
}

int Missing_number_optimal(int arr[], int N)
{
    int sum = N * (N + 1) / 2;
    int sum_arr = 0;
    for (int i = 0; i < N; i++)
    {
        sum_arr += arr[i];
    }

    return (sum - sum_arr);
}

int Missing_Number_Pro(int arr[], int N)
{
    int xor1 = 0;
    int xor2 = 0;

    for (int i = 0; i < N - 1; i++)
    {
        xor2 = xor2 ^ arr[i];
        xor1 = xor1 ^ (i + 1);
    }

    xor1 = xor1 ^ N;
    return xor1 ^ xor2;
}

int main()
{

    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    // int res = Missing_Number_brute(arr, N);
    // int res = Missing_Number_better(arr, N);
    // int res = Missing_number_optimal(arr, N);
    // cout << res << endl;
    // cout<<Missing_number_optimal(arr, N);
    cout << Missing_Number_Pro(arr, N);

    return 0;
}