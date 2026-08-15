class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        
        int n = nums.size() ;
        int total_xor = 0;
        bool has_non_zero = false;

        for (int x : nums) {
            total_xor ^= x;
            if (x > 0) {
                has_non_zero = true;
            }
        }

        if (!has_non_zero) {
            return 0;
        }

        if (total_xor != 0) {
            return nums.size();
        }

        return nums.size() - 1;

    }
};