class Solution {
public:
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        k = k % n;

        // Reverse last k elements
        reverse(nums, n - k, n - 1);

        // Reverse first n-k elements
        reverse(nums, 0, n - k - 1);

        // Reverse the whole array
        reverse(nums, 0, n - 1);
    }
};