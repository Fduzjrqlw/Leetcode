class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int n = A.size() ;
        if (n == 1) {
            return true ;
        }
        int mini = A[n - 1] ;
        for (int i = n - 3 ; i >= 0 ; --i) {
            if (A[i] > mini) {
                return false ;
            }
            mini = min(mini , A[i + 1]) ;
        }
        return true ;
    }
};