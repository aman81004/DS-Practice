class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<int> pathsWithMaxScore( vector<string>& board ) {

        int n = board.size() ;

        // dpScore[i][j] = maximum score from (i,j) to E
        vector<vector<int>> dpScore( n, vector<int>( n , -1 ) ) ;

        // dpWays[i][j] = number of ways to obtain dpScore[i][j]
        vector<vector<int>> dpWays( n , vector<int>( n , 0 ) ) ;

        // Base case: End cell
        dpScore[ n - 1 ][ n - 1 ] = 0 ;
        dpWays[ n - 1 ][ n - 1 ] = 1 ;

        // Fill from bottom-right to top-left
        for ( int i = n - 1 ; i >= 0 ; i-- ) {
            for ( int j = n - 1 ; j >= 0 ; j-- ) {

                if ( board[i][j] == 'X' ) continue ;
                if ( i == n - 1 && j == n - 1 ) continue ;

                int bestScore = -1 ;
                long long ways = 0 ;

                // Down
                if (i + 1 < n && dpScore[i + 1][j] != -1) {
                    if (dpScore[i + 1][j] > bestScore) {
                        bestScore = dpScore[i + 1][j];
                        ways = dpWays[i + 1][j];
                    } else if ( dpScore[i + 1][j] == bestScore ) {
                        ways = ( ways + dpWays[i + 1][j]) % MOD ;
                    }
                }

                // Right
                if ( j + 1 < n && dpScore[i][j + 1] != -1 ) {

                    if ( dpScore[i][j + 1] > bestScore ) {
                        bestScore = dpScore[i][j + 1] ;
                        ways = dpWays[i][j + 1] ;
                    } 

                    else if ( dpScore[i][j + 1] == bestScore) {
                        ways = ( ways + dpWays[i][j + 1]) % MOD ;
                    }

                }

                // Diagonal
                if ( i + 1 < n && j + 1 < n && dpScore[i + 1][j + 1] != -1 ) {
                    if ( dpScore[i + 1][j + 1] > bestScore ) {
                        bestScore = dpScore[i + 1][j + 1] ;
                        ways = dpWays[i + 1][j + 1] ;
                    } else if ( dpScore[i + 1][j + 1] == bestScore ) {
                        ways = ( ways + dpWays[i + 1][j + 1] ) % MOD ;
                    }
                }

                if ( bestScore == -1 ) continue ;

                int val = 0 ;
                if ( board[i][j] >= '0' && board[i][j] <= '9' )
                    val = board[i][j] - '0' ;

                dpScore[i][j] = bestScore + val ;
                dpWays[i][j] = ways % MOD ;
            }
        }

        if ( dpWays[0][0] == 0 )
            return { 0, 0 } ;

        return { dpScore[0][0] , dpWays[0][0] } ;
    }
};