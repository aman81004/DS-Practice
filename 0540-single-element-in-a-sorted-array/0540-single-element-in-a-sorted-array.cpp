class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size() ;
        unordered_map< int , int > map ;

        for( int num : nums ){
            map[num]++ ;
        }

        for( auto &p : map ){
            if( p.second == 1 ) return p.first ;
        }

        return -1 ;

    }
};