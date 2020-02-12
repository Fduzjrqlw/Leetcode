class Solution {
public:

    static int cmp(const vector<int> &A , const vector<int> &B) {
        if (A[0] != B[0]) {
            return A[0] < B[0] ;
        }
        return A[1] > B[1] ;
    }

    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int n = intervals.size() , res = 0 ;
        vector<int> needs(n , 2) ;
        sort(intervals.begin() , intervals.end() , cmp) ;
        for (int i = n - 1 ; i >= 0 ; --i) {
            for (int t = 0 ; t < needs[i] ; ++t) {
                int x = intervals[i][0] + t ;
                for (int j = i - 1 ; j >= 0 ; --j) {
                    if (needs[j] > 0 && x >= intervals[j][0] && x <= intervals[j][1]) {
                        needs[j]-- ;
                    }
                }
                ++res ;
            }
            
        }
        return res ;
    }
};