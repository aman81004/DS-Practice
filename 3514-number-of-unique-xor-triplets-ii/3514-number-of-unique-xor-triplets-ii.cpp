class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        
        int n = nums.size() ;

        int maxVal = 0;
        for (int x : nums) {
            maxVal = std::max(maxVal, x);
        }

        
        int limit = 1;
        while (limit <= maxVal) {
            limit <<= 1;
        }

        vector<bool> pairXorExists(limit, false);
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                pairXorExists[nums[i] ^ nums[j]] = true;
            }
        }

       
        vector<bool> tripletXorExists(limit, false);
        for (int ab = 0; ab < limit; ++ab) {
            if (pairXorExists[ab]) {
                for (int c : nums) {
                    tripletXorExists[ab ^ c] = true;
                }
            }
        }

        int uniqueCount = 0;
        for (int i = 0; i < limit; ++i) {
            if (tripletXorExists[i]) {
                uniqueCount++;
            }
        }

        return uniqueCount;

    }
};