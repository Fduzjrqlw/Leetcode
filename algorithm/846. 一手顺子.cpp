class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        sort(hand.begin() , hand.end()) ;
        int n = hand.size() ;
        if (n % W != 0)
            return false ;
        map<int,int> cnt ;
        for (int i = 0 ; i < n ; ++i) {
            cnt[hand[i]]++ ;
        }

        for (int k = 0 ; k < n / W ; ++k) {
            auto it = cnt.begin() ;
            int f = it->first ;
            for (int i = 0 ; i < W ; ++i) {
                if (cnt.find(f + i) == cnt.end()) {
                    return false ;
                }
                cnt[f + i]-- ;
                if (cnt[f + i] == 0) {
                    cnt.erase(cnt.find(f + i)) ;
                }
            }
        }
        return true ;

    }
};