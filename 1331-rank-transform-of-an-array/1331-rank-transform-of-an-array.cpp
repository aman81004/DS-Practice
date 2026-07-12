class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        int n = arr.size() ;
        vector< int > result( n ) ;

        vector<int> sortedarr = arr; 
        sort(sortedarr.begin(), sortedarr.end());

        unordered_map < int , int > map ;
        int rank = 1 ;
        for( int num : sortedarr ){

            if( map.find( num ) == map.end() ) {
                map[num] = rank ;
                rank++ ;
            }

        }

        for (int i = 0; i < n ; i++) {
            result[i] = map[arr[i]];
        }

        return result ;

    }
};