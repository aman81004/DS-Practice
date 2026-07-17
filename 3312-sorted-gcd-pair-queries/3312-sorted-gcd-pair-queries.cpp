

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size();
        int x = queries.size();

       
        int maxNum = *std::max_element(nums.begin(), nums.end());
        
        vector<int> freq(maxNum + 1, 0);
        for (int num : nums) {
            freq[num]++;
        }
        vector<long long> countDivisors(maxNum + 1, 0);
        for (int i = 1; i <= maxNum; ++i) {
            for (int j = i; j <= maxNum; j += i) {
                countDivisors[i] += freq[j];
            }
        }
        
        vector<long long> countExactGcd(maxNum + 1, 0);
        for (int i = maxNum; i >= 1; --i) {
            long long totalPairs = countDivisors[i] * (countDivisors[i] - 1) / 2;
            for (int j = 2 * i; j <= maxNum; j += i) {
                totalPairs -= countExactGcd[j];
            }
            countExactGcd[i] = totalPairs;
        }
        
       vector<long long> prefixGcdCounts(maxNum + 1, 0);
        for (int i = 1; i <= maxNum; ++i) {
            prefixGcdCounts[i] = prefixGcdCounts[i - 1] + countExactGcd[i];
        }
        
        
        vector<int> ans;
        ans.reserve(x);
        for (int i = 0; i < x; i++) {
            auto it = std::upper_bound(prefixGcdCounts.begin(), prefixGcdCounts.end(), queries[i]);
            ans.push_back(std::distance(prefixGcdCounts.begin(), it));
        }

        return ans;
    }
};