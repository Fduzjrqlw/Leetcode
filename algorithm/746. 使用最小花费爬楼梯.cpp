class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size() ;
        vector<vector<int>> dp(n , vector<int> (2 , 0x7f7f7f)) ;
        dp[0][0] = cost[0] ;
        dp[1][0] = cost[1] ;
        dp[1][1] = cost[0] ;
        for (int i = 1 ; i < n ; ++i) {
            dp[i][1] = min(dp[i][1] , dp[i - 1][0]) ;
            dp[i][0] = min(dp[i][0] , dp[i - 1][0] + cost[i]) ;
            dp[i][0] = min(dp[i][0] , dp[i - 1][1] + cost[i]) ;
            if (i >= 2) {
                dp[i][0] = min(dp[i][0] , dp[i - 2][0] + cost[i]) ;
            }
        }
        return min(dp[n - 1][0] , dp[n - 1][1]) ;
    }
};