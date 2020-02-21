class Solution {
public:
    double soupServings(int N) {
        int n = N / 25 + (N % 25 == 0 ? 0 : 1) ;
        if (n >= 500) {
            return 1.000 ;
        }
        vector<vector<double>> dp(n + 1 , vector<double> (n + 1 , 0)) ;
        for (int i = 0 ; i <= n ; ++i) {
            for (int j = 0 ; j <= n ; ++j) {
                if (i == 0) {
                    dp[i][j] = 1.00 ;
                }
                if (i == 0 && j == 0) {
                    dp[i][j] = 0.50 ;
                }
                if (i > 0 && j > 0) {
                    dp[i][j] = 0.25 * (dp[max(0 , i - 4)][j] + dp[max(0 , i - 3)][max(0 , j - 1)] +
                                    dp[max(0 , i - 2)][max(0 , j - 2)] + dp[max(0 , i - 1)][max(0 , j - 3)]) ;
                }
            }
        }
        return dp[n][n] ;
    }
};