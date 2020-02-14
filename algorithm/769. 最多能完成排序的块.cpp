class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size() ;
        vector<int> Rm(n , 0) , Lm(n , 0) ;
        Rm[0] = arr[0] ;
        Lm[0] = arr[0] ;
        for (int i = 1 ; i < n ; ++i) {
            Rm[i] = max(Rm[i - 1] , arr[i]) ;
            Lm[i] = min(Lm[i - 1] , arr[i]) ;
        }
        vector<int> dp(n , -0x7f7f7f7f) ;
        dp[0] = 1 ;
        for (int i = 1 ; i < n ; ++i) {
            dp[i] = 1 ;
            int t = arr[i] ;
            for (int j = i - 1 ; j >= 0 ; --j) {
                if (t >= Rm[j]) {
                    dp[i] = max(dp[i] , dp[j] + 1) ;
                } 
                t = min(t , arr[j]) ;
            }
        }
        return dp[n - 1] ;
    }
};