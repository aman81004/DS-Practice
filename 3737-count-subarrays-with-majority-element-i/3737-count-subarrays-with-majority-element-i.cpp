class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        
        int n = nums.size() ;
        vector<int> arr(n) ;

        for (int i = 0; i < n; i++) {
            arr[i] = (nums[i] == target) ? 1 : -1;
        }


        long long prefixSum = 0;
        unordered_map<long long,int> freq;
        freq[0] = 1; 
        int result = 0;

        for (int x : arr) {
            prefixSum += x;

            
            for (auto &p : freq) {
                if (prefixSum - p.first > 0) {
                    result += p.second;
                }
            }

            
            freq[prefixSum]++;
        }

        return result;

    }
};