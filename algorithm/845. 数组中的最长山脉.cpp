class Solution {
public:

    int longestMountain(vector<int>& A) {
        int n = A.size() ;
        vector<int> dpl(n , 0) ;
        vector<int> dpr(n , 0) ;
        for (int i = 1 ; i < n ; ++i) {
            if (A[i] > A[i - 1]) {
                dpl[i] = dpl[i - 1] + 1 ;
            }
        }

        for (int i = n - 2 ; i >= 0 ; --i) {
            if (A[i] > A[i + 1]) {
                dpr[i] = dpr[i + 1] + 1 ;
            }
        }

        int res = 0 ;
        if (n <= 2)
            return res ;
        for (int i = 1 ; i + 1 < n ; ++i) {
            if (dpl[i] > 0 && dpr[i] > 0)
                res = max(res , dpl[i] + dpr[i] + 1) ;
        }
        if (res <= 2)
            return 0 ;
        return res ;

    }
};