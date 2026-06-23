class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n = nums.size() ;
        unordered_map<int,int> map ;

        for( int num : nums ){
            map[num]++ ;
        }

        vector<int> ans ;
        for (auto &p : map) {
            if (p.second > n/3) {
                ans.push_back(p.first);
            }
        }

        return ans ;

    }
};