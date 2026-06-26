class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size() ;
        int m = nums2.size() ;

        vector<int> ans ;

        ans.insert(ans.end(), nums1.begin(), nums1.end());
        ans.insert(ans.end(), nums2.begin(), nums2.end());

        sort( ans.begin() , ans.end() ) ;

        int s = ans.size() ;

        if (s % 2 != 0) {
            return ans[s / 2];
        } else {
            return (ans[s / 2 - 1] + ans[s / 2]) / 2.00;
        }

    }
};