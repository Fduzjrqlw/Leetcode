class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size() ;
        vector<vector<long long>> dp(n + 1 , vector<long long> (n + 1 , -0x7f7f7f)) ;
        dp[0][0] = startFuel ;

        if (n == 0) {
            if (startFuel >= target) {
                return 0 ;
            } else return -1 ;
        }

        for (int i = 1 ; i <= n ; ++i) {
            long long d = 0 ;
            if (i == 1) {
                d = stations[i - 1][0] ;
            } else {
                d = stations[i - 1][0] - stations[i - 2][0] ;
            }
            for (int j = 0 ; j <= i ; ++j) {
                //dp[i - 1][j]
                if (dp[i - 1][j] >= d) {
                    dp[i][j] = max(dp[i][j] , dp[i - 1][j] - d) ;
                }
                if (j > 0 && dp[i - 1][j - 1] >= d) {
                    dp[i][j] = max(dp[i][j] , dp[i - 1][j - 1] + stations[i - 1][1] - d) ;
                }
            }
        }
        int res = -1 ;
        for (int j = 0 ; j <= n ; ++j) {
            if (dp[n][j] - (target - stations[n - 1][0]) >= 0) {
                res = j ;
                break ;
            }
        }
        return res ;
    }
};