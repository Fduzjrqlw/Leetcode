class Solution {
public:

    typedef long long ll ;
    int minEatingSpeed(vector<int>& piles, int H) {
        int n = piles.size() ;
        ll l = 1 , r = 0 ;
        for (int i = 0 ; i < n ; ++i) {
            r += (ll) piles[i] ;
        }

        while (l < r) {
            ll mid = l + (r - l) / 2 , t = 0ll ;
            for (int i = 0 ; i < n ; ++i) {
                t += (piles[i] + mid - 1) * 1ll / mid ;
            }
            if (t <= (ll) H) {
                r = mid ;
            } else {
                l = mid + 1 ;
            }   
        }

        return l ;
    }
};