class Solution {
public:

    int dp[1000 + 10][4] ;

    int numTilings(int N) {
        int module = 1e9 + 7 ;
        memset(dp , 0 , sizeof(dp)) ;
        dp[0][3] = 1 ;
        for (int i = 1 ; i <= N ; ++i) {
            dp[i][1] = (dp[i][1] + dp[i - 1][2]) % module ;
            dp[i][2] = (dp[i][2] + dp[i - 1][1]) % module ;
            if (i >= 2){
                dp[i][1] = (dp[i][1] + dp[i - 2][3]) % module ;
                dp[i][2] = (dp[i][2] + dp[i - 2][3]) % module ;
                dp[i][3] = (dp[i][3] + dp[i - 2][3]) % module ;
            }
            dp[i][3] = (dp[i][3] + ((dp[i - 1][3] + dp[i - 1][1]) % module + dp[i - 1][2]) % module) % module ;
        }
        return dp[N][3] ;
    }
};