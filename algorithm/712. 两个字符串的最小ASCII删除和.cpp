class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        if (s1.length() > s2.length()) {
            swap(s1 , s2) ;
        }
        int m = s1.length() , n = s2.length() ;
        int res = 0 ;
        if (m == 0) {
            for (int i = 0 ; i < n ; ++i) {
                res += int(s2[i]) ;
            }
            return res ;
        }
        vector<vector<int>> dp(m + 1 , vector<int> (n + 1 , 0x7f7f7f7f)) ;
        dp[0][0] = 0 ;
        for (int i = 1 ; i <= n ; ++i) {
            dp[0][i] = dp[0][i - 1] + int(s2[i - 1]) ;
        }
        for (int i = 1 ; i <= m ; ++i) {
            dp[i][0] = dp[i - 1][0] + int(s1[i - 1]) ;
        }
        for (int i = 1 ; i <= m ; ++i) {
            for (int j = 1 ; j <= n ; ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] ;
                }
                dp[i][j] = min(dp[i][j] , dp[i - 1][j] + int(s1[i - 1])) ;
                dp[i][j] = min(dp[i][j] , dp[i][j - 1] + int(s2[j - 1])) ;
                dp[i][j] = min(dp[i][j] , dp[i - 1][j - 1] + int(s1[i - 1] + int(s2[j - 1]))) ;
            }
        }
        return dp[m][n] ;
    }
};