class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int n = A.size() ;
        vector<int> preSum(n + 1 , 0) ;
        for (int i = 1 ; i <= n ; ++i) {
            preSum[i] += preSum[i - 1] + A[i - 1] ;
        }
        vector<vector<double>> dp(n + 1 , vector<double> (n + 1 , 0.000)) ;

        for (int i = 1 ; i <= n ; ++i) {
            dp[i][1] = 1.00 * preSum[i] / (i * 1.00) ;
        }

        for (int i = 2 ; i <= K ; ++i) {
            for (int j = i ; j <= n ; ++j) {
                for (int k = i - 1 ; k < j ; ++k) {
                    dp[j][i] = max(dp[j][i] , dp[k][i - 1] + (preSum[j] - preSum[k]) * 1.00 / (j - k) * 1.00) ;
                }
            }
        }
        return dp[n][K] ;

    }
};