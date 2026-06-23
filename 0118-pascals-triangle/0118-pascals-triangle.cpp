class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        int n = numRows ;
        vector<vector<int>> pascalTriangle(n) ;

        for( int i = 0 ; i < n ; i++ ){
           
            pascalTriangle[i].resize( i + 1 );
            pascalTriangle[i][0] = pascalTriangle[i][i] = 1;

            for( int j = 1 ; j < i ; j++ ){
                pascalTriangle[i][j] = pascalTriangle[ i - 1][ j - 1 ] + pascalTriangle[ i - 1 ][j] ; 
            }

        }

        return pascalTriangle;
    }
};