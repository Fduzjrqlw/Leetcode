class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size() ;
        vector<bool> dp(n , false) ;
        if (bits[n - 1] == 0) {
            dp[n - 1] = true ;
        } else dp[n - 1] = false ;
        for (int i = n - 2 ; i >= 0 ; --i) {
            if (bits[i] == 0) {
                dp[i] = dp[i + 1] ;
            } else if (bits[i] == 1 && i + 2 < n) {
                dp[i] = dp[i + 2] ;
            }
        }
        return dp[0] ;
    }
};