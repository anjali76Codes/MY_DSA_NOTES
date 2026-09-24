class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int>> ans;

        // two pointer - array must be sorted
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {

            // if i > 0 means it is not first triplet
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int l = i + 1;
            int r = n - 1;

            while (l < r) {

                int sum = nums[i] + nums[l] + nums[r];

                if (sum == 0) {

                    ans.push_back({nums[i], nums[l], nums[r]});

                    // We don't want duplicate triplets.
                    // Move l while the next element is the same.
                    while (l < r && nums[l] == nums[l + 1])
                        l++;

                    // Move r while the previous element is the same.
                    while (l < r && nums[r] == nums[r - 1])
                        r--;

                    l++;
                    r--;
                }
                else if (sum > 0) {
                    r--;
                }
                else {
                    l++;
                }
            }
        }

        return ans;
    }
};