class Solution {
public:

    bool check(vector<int>& A , int target , int m , int sum) {
        int n = A.size() ;
        vector<vector<bool>> dp(m + 1 , vector<bool> (target + 1 , false)) ;
        dp[0][0] = true ;
        for (int i = 0 ; i < n ; ++i) {
            for (int j = m ; j >= 1 ; --j) {
                for (int k = target ; k >= A[i] ; --k) {
                    dp[j][k] = dp[j][k] | dp[j - 1][k - A[i]] ;
                }
            }
        }
        return dp[m][target] ;
    }

    bool splitArraySameAverage(vector<int>& A) {
        int n = A.size() , sum = 0 ;
        for (int i = 0 ; i < n ; ++i) {
            sum += A[i] ;
        }
        for (int k = 1 ; k * 2 <= n ; ++k) {
            if ((sum * k % n) == 0) {
                if (check(A , sum * k / n , k , sum)) {
                    int s0 = sum * k / n ;
                    return true ;
                }
            }
        }
        return false ;
    }
};