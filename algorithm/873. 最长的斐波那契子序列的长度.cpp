class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int n = A.size() , res = 0 ;

        vector<vector<int>> dp(n , vector<int>(n , -0x7f7f7f)) ;
        unordered_map<int,int> pos ;

        for (int i = 0 ; i < n ; ++i) {
            pos[A[i]] = i ;
        }

        for (int i = 1 ; i < n ; ++i) {
            dp[i][0] = 2 ;
            for (int j = 1 ; j < i ; ++j) {
                if (pos.find(A[i] - A[j]) == pos.end() || pos[A[i] - A[j]] >= j) {
                    dp[i][j] = 2 ;
                } else {
                    dp[i][j] = dp[j][pos[A[i] - A[j]]] + 1 ;
                }
                res = max(res , dp[i][j]) ;
            }
        }

        if (res <= 2) {
            res = 0 ;
        }
        return res ;
    }
};