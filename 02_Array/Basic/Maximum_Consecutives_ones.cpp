#include<bits/stdc++.h>

using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int cnt = 0;
    int max_cnt = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            cnt++;
        } else {
            cnt = 0;
        }
        max_cnt = max(max_cnt, cnt);
    }
    return max_cnt;
}

int main() {
    // Example 1: Input vector
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    
    // Calling the function and printing the result
    cout << "Max consecutive ones: " << findMaxConsecutiveOnes(nums) << endl;

    // Example 2: Another input vector
    vector<int> nums2 = {1, 0, 1, 1, 0, 1};
    
    cout << "Max consecutive ones: " << findMaxConsecutiveOnes(nums2) << endl;

    return 0;
}
