class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size() ;
        vector<vector<int>> dp(n , vector<int> (n , 0)) ;

        for (int i = 0 ; i < n ; ++i)
            dp[i][i] = -piles[i] ;

        for (int l = 2 ; l <= n ; ++l) {
            for (int i = 0 ; i < n ; ++i) {
                int j = i + l - 1 ;
                if (j >= n)
                    break ;
                if (l % 2 == 1) {
                    dp[i][j] = min(dp[i + 1][j] - piles[i] , dp[i][j - 1] - piles[j]) ;
                } else {
                    dp[i][j] = max(dp[i + 1][j] + piles[i] , dp[i][j - 1] + piles[j]) ;
                }
            }
        }
        if (dp[0][n - 1] > 0) {
            return true ;
        }
        return false ;
    }
};