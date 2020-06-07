class Solution {
public:

    const int module = 1e9 + 7 ;

    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        
        int s = 0 , n = group.size() ;
        for (int i = 0 ; i < n ; ++i) {
            s += profit[i] ;
        }

        //dp[j][v] 用了j个人,利润为v的方案数

        vector<vector<int>> dp(G + 1 , vector<int> (P + 1 , 0)) ;

        dp[0][0] = 1 ;

        
        for (int i = 0 ; i < n ; ++i) {
            for (int j = G ; j >= group[i] ; --j) {
                for (int v = P ; v >= max(0 , P - profit[i]) ; --v)
                    dp[j][P] = (dp[j][P] + dp[j - group[i]][v]) % module ;
                for (int v = P - 1 ; v >= profit[i] ; --v) {
                    dp[j][v] = (dp[j][v] + dp[j - group[i]][v - profit[i]]) % module ;
                }
            }
        }

        int res = 0 ;
        for (int i = 0 ; i <= G ; ++i) {
            res = (res + dp[i][P]) % module ;
        }
        return res ;
    }
};