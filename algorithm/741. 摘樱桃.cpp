class Solution {
public:
    int dp[110][51][51] ;
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size() ;
        memset(dp , -1 , sizeof(dp)) ;
        dp[0][0][0] = grid[0][0] ;
        for (int l = 0 ; l < 2 * n - 2 ; ++l) {
            for (int i = 0 ; i < n ; ++i) {
                for (int j = 0 ; j < n ; ++j) {
                    if (dp[l][i][j] == -1) {
                        continue ;
                    }
                    
                    //(i , p) , (j , q)
                    int p = l - i , q = l - j ;
                    if (p < 0 || p >= n || q < 0 || q >= n) continue ;
                    //cout << l << " (" << i << " , " << p << ") , (" << j << " ,  " << q << ")" << endl ; 
                    //(i , p) -> (i , p + 1) , (j , q) - > (j , q + 1)
                    if (p + 1 < n && q + 1 < n && grid[i][p + 1] != -1 && grid[j][q + 1] != -1) {
                        if (i == j) {
                            dp[l + 1][i][j] = max(dp[l + 1][i][j] , dp[l][i][j] + grid[i][p + 1]) ;
                        } else {
                            dp[l + 1][i][j] = max(dp[l + 1][i][j] , dp[l][i][j] + grid[i][p + 1] + grid[j][q + 1]) ;
                        }
                    }
                    //(i , p) -> (i + 1 , p) , (j , q) -> (j , q + 1)
                    if (i + 1 < n && q + 1 < n && grid[i + 1][p] != -1 && grid[j][q + 1] != -1) {
                        if (i + 1 == j) {
                            dp[l + 1][i + 1][j] = max(dp[l + 1][i + 1][j] , dp[l][i][j] + grid[i + 1][p]) ;
                        } else {
                            dp[l + 1][i + 1][j] = max(dp[l + 1][i + 1][j] , dp[l][i][j] + grid[i + 1][p] + grid[j][q + 1]) ;
                        }
                    }
                    //(i , p) -> (i , p + 1) , (j , q) -> (j + 1 , q)
                    if (p + 1 < n && j + 1 < n && grid[i][p + 1] != -1 && grid[j + 1][q] != -1) {
                        if (i == j + 1) {
                            dp[l + 1][i][j + 1] = max(dp[l + 1][i][j + 1] , dp[l][i][j] + grid[i][p + 1]) ;
                        } else {
                            dp[l + 1][i][j + 1] = max(dp[l + 1][i][j + 1] , dp[l][i][j] + grid[i][p + 1] + grid[j + 1][q]) ;
                        }
                    }
                    //(i , p) -> (i + 1 ,p) , (j , q) -> (j + 1 , q)
                    if (i + 1 < n && j + 1 < n && grid[i + 1][p] != -1 && grid[j + 1][q] != -1) {
                        if (i == j) {
                            dp[l + 1][i + 1][j + 1] = max(dp[l + 1][i + 1][j + 1] , dp[l][i][j] + grid[i + 1][p]) ;
                        } else {
                            dp[l + 1][i + 1][j + 1] = max(dp[l + 1][i + 1][j + 1] , dp[l][i][j] + grid[i + 1][p] + grid[j + 1][q]) ;
                        }
                    }
                }
            }
        }
        if (dp[2 * n - 2][n - 1][n - 1] == -1) {
            return 0 ;
        }
        return dp[2 * n - 2][n - 1][n - 1] ;
    }
};