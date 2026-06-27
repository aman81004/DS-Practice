class Solution {
public:
    int maximumLength(vector<int>& nums) {
        
        unordered_map<long long,int> freq;
        long long maxNum = 0;
        for (int num : nums) {
            freq[num]++;
            maxNum = max(maxNum, (long long)num);
        }

        int ans = 1;

        // Special case for 1
        if (freq.count(1)) {
            int ones = freq[1];
            if (ones % 2 == 0) ans = max(ans, ones - 1);
            else ans = max(ans, ones);
        }

        for (int num : nums) {
            if (num == 1) continue;
            long long x = num;
            int length = 0;
            while (x <= maxNum && freq.count(x) && freq[x] >= 2) {
                length += 2;
                x = x * x;
            }
            if (freq.count(x)) {
                ans = max(ans, length + 1);
            } else {
                ans = max(ans, length - 1);
            }
        }

        return ans;

    }
};