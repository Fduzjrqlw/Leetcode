class Solution {
public:

    int res ;

    void solve(vector<vector<int>>& A) {
        int m = A.size() , n = A[0].size() ;
        int t = 0 ;
        vector<int> temp(m , 0) ;
        for (int i = 0 ; i < m ; ++i) {
            if (A[i][0] == 0) {
                temp[i] = 1 ;
            }
            t += (1 << (n - 1)) ;
        }
        for (int j = 1 ; j < n ; ++j) {
            int c = 0 ;
            for (int i = 0 ; i < m ; ++i) {
                if ((A[i][j] ^ temp[i]) == 1) {
                    ++c ;
                }
            }
            if (m - c > c) {
                c = m - c ;
            }
            t += c * (1 << (n - 1 - j)) ;
        }
        res = max(res , t) ;
    }

    int matrixScore(vector<vector<int>>& A) {
        int m = A.size() , n = A[0].size() ;
        
        solve(A) ;
        for (int i = 0 ; i < m ; ++i) {
            A[i][0] ^= 1 ;
        }
        solve(A) ;

        return res ;
    }
};