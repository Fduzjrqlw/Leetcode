class Solution {
public:
    int bestRotation(vector<int>& A) {
        int n = A.size() ;
        vector<int> count(n + 1 , 0) ;

        for (int i = 0 ; i < n ; ++i) {
            int l = 0 , r = min(i - A[i] , i) ;
            if (r >= l) {
                count[l]++ ;
                count[r + 1]-- ;
            }
            l = i + 1 ; r = min(n + i - A[i] , n - 1) ;
            if (r >= l) {
                count[l]++ ;
                count[r + 1]-- ;
            }
        }
        int res = 0 , s = 0 , pos = 0 ;
        for (int i = 0 ; i <= n ; ++i) {
            s += count[i] ;
            if (s > res) {
                res = s ;
                pos = i ;
            }
        }
        return pos ;
    }
};