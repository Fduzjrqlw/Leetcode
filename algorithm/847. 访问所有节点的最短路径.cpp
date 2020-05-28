class Solution {
public:

    int f[13][13] ;
    int dp[1 << 12][12] ;

    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size() ;

        memset(f , 0x3f , sizeof(f)) ;


        for (int i = 0 ; i < n ; ++i) {
            f[i][i] = 0 ;
            for (int j = 0 ; j < graph[i].size() ; ++j) {
                f[i][graph[i][j]] = 1 ;
            }
        }

        for (int k = 0 ; k < n ; ++k) {
            for (int i = 0 ; i < n ; ++i) {
                for (int j = 0 ; j < n ; ++j) {
                    f[i][j] = min(f[i][k] + f[k][j] , f[i][j]) ;
                }
            }
        }

        int res = 0x3f ;
        for (int s = 0 ; s < n ; ++s) {
            memset(dp , 0x3f , sizeof(dp)) ;
            dp[1 << s][s] = 0 ;

            for (int state = 1 ; state < (1 << n) ; ++state) {
                for (int i = 0 ; i < n ; ++i) {
                    if ((state >> i) & 1) {
                        for (int j = 0 ; j < n ; ++j) {
                            if ((state >> j) & 1) {
                                dp[state][i] = min(dp[state][i] , dp[state ^ 1 << i][j] + f[j][i]) ;
                            }
                        }
                    }
                }
            }

            for (int i = 0 ; i < n ; ++i) {
                res = min(res , dp[(1 << n) - 1][i]) ;
            }
        }

        return res ;
    }
};