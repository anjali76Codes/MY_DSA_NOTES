/*
Maximum subarray sum
# Brute approach :
1.  initialize msum = INT_MIN and use three loops
2. inner loop j and  k = i and  k<=j to get sum
3. sum = sum + arr[k]
4. maxsum = max(maxsum, sum)
4. return maxsum


time complexity : approximate O(n3)
space complexity : O(1)


# Better Approach :
1. Initialize maxsum = INT_MIN
2. use two loop and calculate sum
3. maxsum = max(maxsum, sum)
4. return maxsum

time complexity : O(n2)
space complexity : O(1)



# Optimal approach :
# Kadane's algorithm
1. Initialize maxsum = LONG_MIN and  sum = 0
2.for loop for iterating on each ele
3. sum = sum+arr[i]
4.if (sum<0) then assign sum = 0
5. if(sum>maxsum) then maxsum = sum
6. return maxsum

time complexity : O(n)
space complexity : O(1)

## If I have to print the subarray who's sum is max
then need to this code snippet
1. initialize ansStart = -1 and ansEnd = -1 and start = 0 
2. when sum == 0 we start so start = i+1
3. and in where sum> maxsum add this part:
    - ansStart = start  and ansEnd = i ;





*/

#include <bits/stdc++.h>
using namespace std;

int Maximum_SubarraySum_brute(vector<int> &arr, int n)
{
    int max_sum = INT_MIN;
    // three loops
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;

            // find sum and update each time maxsum
            for (int k = i; k <= j; k++)
            {
                sum = sum + arr[k];
                max_sum = max(max_sum, sum);
            }
        }
    }

    return max_sum;
}

int Maximum_SubarraySum_better(vector<int> &arr, int n)
{
    int maxsum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum = sum + arr[j];
            maxsum = max(maxsum, sum);
        }
    }

    return maxsum;
}


long long Maximum_SubarraySum_optimal(vector<int> &arr, int n)
{
    long long maxsum = LONG_MIN, sum = 0;
    int start = 0, ansStart = -1, ansEnd = -1;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        // When sum is negative, reset sum to 0 and move start to the next element
        if (sum < 0)
        {
            sum = 0;
            start = i + 1; // Start the new subarray from the next element
        }

        // When sum is greater, update maxsum and the corresponding start and end indices
        if (sum > maxsum)
        {
            maxsum = sum;
            ansStart = start;
            ansEnd = i;
        }
    }

    // Print the subarray with the maximum sum
    cout <<endl<< "Subarray with the maximum sum: ";
    for (int i = ansStart; i <= ansEnd; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return maxsum;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    cout << Maximum_SubarraySum_brute(arr, n);
    cout << Maximum_SubarraySum_better(arr, n);
    cout << Maximum_SubarraySum_optimal(arr, n);

    return 0;
}