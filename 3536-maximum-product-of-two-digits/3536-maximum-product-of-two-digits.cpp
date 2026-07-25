class Solution {
public:
    int maxProduct(int n) {
        
        string s = to_string( n ) ;
        sort( s.rbegin() , s.rend() ) ;

        int first = s[0]  - '0' ;
        int second = s[1] - '0' ;

        return  first * second ;


    }
};