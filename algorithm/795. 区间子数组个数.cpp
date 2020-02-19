class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int n = A.size() , res = 0 ;
        int pos = -1 ;
        vector<int> dp(n , 0) ;
        for (int i = 0 ; i < n ; ++i) {
            if (A[i] >= L && A[i] <= R) {
                if (pos == -1) {
                    dp[i] = i + 1 ;
                    res += i + 1 ;
                } else {
                    dp[i] = i - pos ;
                    res += (i - pos) ;
                }
            } else if (A[i] > R) {
                pos = i ;
            } else {
                if (i >= 1)
                    dp[i] = dp[i - 1] ;
                res += dp[i] ;
            }
        }
        return res ;
    }
};