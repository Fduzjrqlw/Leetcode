class Solution {
public:

    int res , n ;

    void dfs(int pos , int step , string& A , string &B) {
        if (step >= res)
            return ;
        if (pos == n) {
            res = min(res , step) ;
            return ;
        }
        if (A[pos] == B[pos]) {
            dfs(pos + 1 , step , A , B) ;
        } else {
            for (int i = pos + 1 ; i < n ; ++i) {
                if (A[i] == B[pos] && A[i] != B[i]) {
                    swap(A[i] , A[pos]) ;
                    dfs(pos + 1 , step + 1 , A , B) ;
                    swap(A[i] , A[pos]) ;
                }
            }
        }
    }

    int kSimilarity(string A, string B) {
        n = A.length() ;
        res = n + 1 ;
        dfs(0 , 0 , A , B) ;
        return res ;
    }
};