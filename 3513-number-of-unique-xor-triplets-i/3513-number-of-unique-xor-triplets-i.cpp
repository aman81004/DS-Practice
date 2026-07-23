class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        
       
        if (n < 3) {
            return n;
        }
      
        return 1 << bit_width(static_cast<unsigned int>(n));
    }
};