class Solution {
public:

    double dp[110][110] ;
    double champagneTower(int poured, int query_row, int query_glass) {
        ++query_row ; ++query_glass ;
        dp[1][1] = poured * 1.00 ;

        for (int i = 1 ; i <= query_row ; ++i) {
            for (int j = 1 ; j <= i ; ++j) {
                if (dp[i][j] >= 1.00) {
                    dp[i + 1][j] += 0.5 * (dp[i][j] - 1) ;
                    dp[i + 1][j + 1] += 0.5 * (dp[i][j] - 1) ;
                    dp[i][j] = 1.00 ;
                }
            }
        }
        return dp[query_row][query_glass] ;

    }
};