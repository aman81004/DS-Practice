class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return -1;

        // suffix_min[i] will store min(nums[i..n-1])
        vector<int> suffix_min(n);
        suffix_min[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffix_min[i] = min(nums[i], suffix_min[i + 1]);
        }

        // Traverse from left to right, maintaining max(nums[0..i])
        int prefix_max = nums[0];
        for (int i = 0; i < n; ++i) {
            prefix_max = max(prefix_max, nums[i]);
            if (prefix_max - suffix_min[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};