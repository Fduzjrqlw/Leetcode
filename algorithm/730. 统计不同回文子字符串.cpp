class Solution {
public:
    //非常巧妙的DP题
    //dp[i][j]表示S[i...j]的不同回文子序列个数
    //怎么去掉重复部分?
    //如果S[i] != S[j], dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] (中间计算两遍的减掉)
    //如果S[i] == S[j], 找在i右边的S[i]相同的第一个位置left,在j右边的和S[j]相同的第一个位置right
    //通过left和right的关系,判断S[i + 1] ~ S[j - 1]有多少个S[i]
    //如果有0个,那么dp[i][j] = (dp[i + 1][j - 1] * 2 + 2)  其中的2表示单个S[i]以及S[i]+S[i]这两个情况
    //如果有1个,那么dp[i][j] = (dp[i + 1][j - 1] * 2 + 1)  其中的1表示S[i]+S[i]
    //如果有多个,那么dp[i][j] = (dp[i + 1][j - 1] * 2 - dp[left + 1][right - 1])
    int countPalindromicSubsequences(string S) {
        int mod = 1e9 + 7 ;
        int n = S.length() ;
        vector<vector<int>> dp(n + 1 , vector<int> (n + 1 , 0)) ;
        for (int i = 1 ; i <= n ; ++i) {
            dp[i][i] = 1 ;
        }
        for (int len = 2 ; len <= n ; ++len) {
            for (int i = 1 ; i <= n ; ++i) {
                int j = i + len - 1 ;
                if (j > n) {
                    break ;
                }
                if (S[i - 1] == S[j - 1]) {
                    int left = i + 1 , right = j - 1 ;
                    while (left < j && S[left - 1] != S[i - 1]) {
                        ++left ;
                    }
                    while (right > i && S[right - 1] != S[i - 1]) {
                        --right ;
                    }
                    if (right < left) {
                        dp[i][j] = (dp[i + 1][j - 1] * 2 + 2) % mod ;
                    } else if (right == left) {
                        dp[i][j] = (dp[i + 1][j - 1] * 2 + 1) % mod ;
                    } else {
                        dp[i][j] = (dp[i + 1][j - 1] * 2 % mod + (mod - dp[left + 1][right - 1])) % mod ;
                    }
                } else  {
                    dp[i][j] = (dp[i + 1][j] + dp[i][j - 1]) % mod ;
                    dp[i][j] = (dp[i][j] + (mod - dp[i + 1][j - 1]) % mod) % mod ;
                }
            }
        }
        return dp[1][n] ;
    }
};