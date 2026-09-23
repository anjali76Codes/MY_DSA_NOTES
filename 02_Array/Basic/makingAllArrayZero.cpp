#include<bits/stdc++.h>
using namespace std;



/*
Problem:
I have an array of numbers. In one operation, I can pick any part of the array (a subarray) and turn all the smallest numbers in that part into 0. I want to do this until all numbers are 0, using as few operations as possible.

Example:
Array: [3,1,2,1]

Pick [1,3] → numbers [1,2,1], smallest is 1 → turn all 1s to 0 → [3,0,2,0]

Pick [2,2] → number [2], smallest is 2 → turn it to 0 → [3,0,0,0]

Pick [0,0] → number [3] → turn it to 0 → [0,0,0,0]

 Minimum operations = 3
*/
// brute Approach 
    int minOperations(vector<int>& nums) {
        unordered_set<int> st(begin(nums), end(nums));
        int n = nums.size();
        int ops = 0;
        for (int target : st) {
            if (target == 0)
                continue;
           
           
            bool flow = false;
            for (int i = 0; i < n; i++) {
                if (nums[i] == target) {
                    if(!flow){
                   flow = true;
                    ops++;

                    }
                   
                
                } else if (nums[i] < target) {
                    flow = false;
                
                }
            }
        }
        return ops;
    }



// optimal approach - monotonic stack 
 int minOperations(vector<int>& nums) {
        int n = nums.size();

        stack<int>st;
        int ops = 0;
     for(int i =0 ; i<n ; i++){

        while(!st.empty() && st.top()>nums[i]){
            st.pop();
        }

        if(nums[i]==0)
        continue;
        if(st.empty() || nums[i]>st.top()){
               ops++;
            st.push(nums[i]);
        }
       
     }
     return ops;   
    }

    int main()
{
    vector<int>nums = {1,2,1,2,1,2};
    cout<<minOperations(nums);

return 0;
}
