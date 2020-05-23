class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int n = fronts.size() , tot = 0 ;
        int res = 0x7f7f7f ;
        unordered_map<int,int> nums ;
        for (int i = 0 ; i < n ; ++i) {
            nums[fronts[i]]++ ;
            nums[backs[i]]++ ;
        }

        for (int i = 0 ; i < n ; ++i) {
            if (fronts[i] == backs[i]) {
                continue ;
            }
            int x = fronts[i] ;
            bool test = true ;

            for (int j = 0 ; j < n ; ++j) {
                if (i == j) {
                    continue ;
                }
                if (fronts[j] == x && backs[j] == x) {
                    test = false ;
                    break ;
                }
            }

            if (test) {
                res = min(res , x) ;
            }

            test = true ;
            x = backs[i] ;

            for (int j = 0 ; j < n ; ++j) {
                if (i == j) {
                    continue ;
                }
                if (fronts[j] == x && backs[j] == x) {
                    test = false ;
                    break ;
                }
            }
            if (test) {
                res = min(res , x) ;
            }
        }

        if (res == 0x7f7f7f) {
            res = 0 ;
        }
        return res ;
    }
};