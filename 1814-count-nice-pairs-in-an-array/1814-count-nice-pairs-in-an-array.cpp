class Solution {
public:
    int rev(int n) {
        int r = 0;
        while (n > 0) {
            r = r * 10 + (n % 10);
            n /= 10;
        }
        return r;
    }

    int countNicePairs(vector<int>& nums) {
        int MOD = 1e9 + 7;
        long long pairs = 0;
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); i++) {
            int diff = nums[i] - rev(nums[i]);

            // If we've seen this diff before, it pairs with all previous instances
            if (m.find(diff) != m.end()) {
                pairs = (pairs + m[diff]) % MOD;
            }

            // Record current diff in the map
            m[diff]++;
        }

        return pairs;
    }
};