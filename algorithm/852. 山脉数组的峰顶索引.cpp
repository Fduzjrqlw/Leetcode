class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int n = A.size() ;
        vector<int> l(n , 0) , r(n , 0) ;
        for (int i = 1 ; i < n ; ++i) {
            if (A[i] > A[i - 1]) {
                l[i] = l[i - 1] + 1 ;
            }
        }
        for (int i = n - 2 ; i >= 0 ; --i) {
            if (A[i] > A[i + 1]) {
                r[i] = r[i + 1] + 1 ;
            }
        }
        for (int i = 1 ; i + 1 < n ; ++i) {
            if (l[i] > 0 && r[i] > 0) {
                return i ;
            }
        }
        return 0 ;
    }
};