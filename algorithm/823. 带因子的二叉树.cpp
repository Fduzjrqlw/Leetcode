class Solution {
public:

    typedef long long ll ;
    const ll module = 1e9 + 7 ;
    int numFactoredBinaryTrees(vector<int>& A) {
        int n = A.size() ;
        sort(A.begin() , A.end()) ;
        
        unordered_map<int,ll> dp ;
        ll res = 0ll ;

        for (int i = 0 ; i < n ; ++i) {
            ll t = 1ll ;
            for (int j = 0 ; j < i ; ++j) {
                if (A[i] % A[j] == 0) {
                    if (A[i] / A[j] == A[j]) {
                        t = t + (dp[A[j]] * dp[A[j]]) % module ;
                        t %= module ;
                    } else {
                        t = t + (dp[A[j]] * dp[A[i] / A[j]]) % module ;
                        t %= module ;
                    }
                }
            }
            dp[A[i]] = t ;
            res = (res + t) % module ;
        }
        return res ;
    }
};