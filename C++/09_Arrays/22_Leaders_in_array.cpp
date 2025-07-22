/*
Leaders in array
Leaders : Everything in right should be smaller

# Brute Approach :
1.Iterate through the array using two loops.
For each element, assume it's a leader (leaders = true).
Check if any element after it is greater; if so, set leaders = false.
If it remains a leader, add it to ans.
Return ans.

time complexity : O(n^2)
space complexity : O(n)


# Optimal approach : 
1. Start from right, initialize maxi = INT_MIN
2. Loop through the array
3. If arr[i] > maxi, add arr[i] to ans
4. Update maxi = max(maxi, arr[i])
5 .Sort ans
6 .Return ans

time complexity : O(n)+ O(nlogn) - in worst case (where all are leaders and not in sorted form)

space complexity : O(n) - not used to solve but use for the returning the ans (return leaders)

*/

#include <bits/stdc++.h>
using namespace std;

vector<int> Leaders_in_array_brute(vector<int> &arr, int n)
{

vector<int> ans ;
    for (int i = 0; i < n; i++)
    {
       bool leaders = true;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                leaders = false;
                break;
            }
        }


        if(leaders == true){
        ans.push_back(arr[i]);
    }
    }

    return ans ; 

    
}


vector<int> Leaders_in_array_optimal(vector<int> &arr, int n)
{
    vector<int>ans ;
    int maxi = INT_MIN;

    for(int i = n-1 ; i>=0 ; i--){
        if(arr[i] > maxi ){
            ans.push_back(arr[i]);
        }

        // keep track of right max 
        maxi  = max(maxi , arr[i]);

    }

    sort(ans.begin(), ans.end());
    return ans ;


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

    vector<int> res1 = Leaders_in_array_brute(arr, n);
    vector<int> res2 = Leaders_in_array_optimal(arr, n);
    for (auto it : res2)
    {
        cout << it << endl;
    }

    return 0;
}