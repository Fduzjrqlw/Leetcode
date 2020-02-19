class Solution {
public:

    long long f(long long x) {
        long long s = 0 ;
        long long mul = 5ll ;
        while (x / mul) {
            s += (x / mul) ;
            mul = mul * 5ll ;
        }
        return s ;
    }

    int preimageSizeFZF(int K) {
        if (K == 0) {
            return 5 ;
        }
        long long l = 1 , r = 1e16 ;
        while (l < r) {
            long long mid = (l + r + 1) >> 1 ;
            if (f(mid) <= K) {
                l = mid ;
            } else {
                r = mid - 1 ;
            }
        }
        //cout << l << " " << f(l) << endl ;
        if (f(l) == K)
            return 5 ;
        return 0 ;
    }
};