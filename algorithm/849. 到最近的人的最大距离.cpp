class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int res = 0 , n = seats.size() ;
        vector<int> dpl(n , -1) ;
        vector<int> dpr(n , -1) ;
        for (int i = 0 ; i < n ; ++i) {
            if (seats[i] == 1) {
                dpl[i] = i ;
            } else {
                if (i > 0) {
                    dpl[i] = dpl[i - 1] ;
                }
            }
        }
        for (int i = n - 1 ; i >= 0 ; --i) {
            if (seats[i] == 1) {
                dpr[i] = i ;
            } else {
                if (i != n - 1) {
                    dpr[i] = dpr[i + 1] ;
                }
            }
        }

        for (int i = 0 ; i < n ; ++i) {
            if (seats[i] == 0) {
                int t = 0x3f ;
                if (dpl[i] != -1) {
                    t = min(t , i - dpl[i]) ;
                }
                if (dpr[i] != -1) {
                    t = min(t , dpr[i] - i) ;
                }
                res = max(res , t) ;
            }
        }
        return res ;
    }
};