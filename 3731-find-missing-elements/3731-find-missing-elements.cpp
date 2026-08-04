class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        auto [minIt, maxIt] = std::minmax_element(nums.begin(), nums.end());
        int minNum = *minIt;
        int maxNum = *maxIt;

        unordered_set<int> present(nums.begin(), nums.end());

        vector<int> result;
        for (int i = minNum; i <= maxNum; ++i) {
            if (present.find(i) == present.end()) {
                result.push_back(i);
            }
        }

        return result;
    }
};