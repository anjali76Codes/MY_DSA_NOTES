/*
Two sum :

Brute Approach :
1. outer loop -> 0 to n-1
2. inner loop -> 0 t n-1
3. calculate sum
4. if sum = target  return string/index
5.return index/string

optimization for this : j = i+1;




Better Approach :
1.create hashmap
2. for loop from 0 to n-1
3.  declare sum  -> arr[i]
4. find remaining -> target - sum
5. and check condition if the remaining is present in the map or not
        - If yes print "YES"
        - if no then add it -> hashmap[sum] = i (in this form)
6. return string / index

Complexity :
time : in map DS -  O(nlogn) but in case of unordered map - O(n) and in worst case it can be O(n^2)

space : O(n)



optimal approach :
using two pointer

1. left assign = 0
2. right assign = n-1
3.sort the array
4. while left < right
    - if left + right == target then return "YES"
    - if left + right < target then left++
    - if left + right > target then right--
5. return "NO"

but this above one is optimal only for the variety 1 (show YES or NO) but not for variety 2(with indexes)
( because if I have to show indexes as well then first I have to store all elements with its index in somewhere  and then need to sort it so it can't be an  optimal way to solve this )


*/

#include <bits/stdc++.h>
using namespace std;

string TwoSum_brute(vector<int> &arr, int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        int sum = 0 ;
        for (int j = i + 1; j < n; j++)
        {
            sum = arr[i] + arr[j];
            if (sum == target)
            {
                // cout << "YES" << endl;
                // cout << i << " " << j << endl;
                return "YES";
            }
        }
    }
    return "NO";
}

string TwoSum_better(vector<int> &arr, int n, int target)
{
    // declaration
    map<int, int> hmap;

    // iterate across array
    for (int i = 0; i < n; i++)
    {
        int sum = arr[i];
        int rem = target - sum;
        if (hmap.find(rem) != hmap.end())
        {
            return "YES"; //  for index-{ hmap[rem], i } ;
        }
        hmap[sum] = i;
    }
    return "No";
    // return {-1 ,-1};
}

string TwoSum_optimal(vector<int> &arr, int n, int target)
{
    int left = 0;
    int right = n - 1;
    sort(arr.begin(), arr.end());

    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == target)
        {
            return "YES";
        }
        if (sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return "NO";
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        arr.push_back(ele);
    }

    int target;
    cin >> target;

    // for(auto it : arr){
    //     cout<<it<<" ";
    // }

    cout << TwoSum_brute(arr, n, target);
    cout << TwoSum_better(arr, n, target);
    cout << TwoSum_optimal(arr, n, target);

    /* to print indices
      pair<int, int> result = TwoSum_better(arr, n, target);

        if (result.first != -1)
        {
            cout << "Indices: " << result.first << ", " << result.second << endl;
        }
        else
        {
            cout << "No such pair found" << endl;
        }

        */

    return 0;
}