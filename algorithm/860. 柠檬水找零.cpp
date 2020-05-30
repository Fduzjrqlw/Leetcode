class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f1 = 0 , f2 = 0 , n = bills.size() ;
        for (int i = 0 ; i < n ; ++i) {
            if (bills[i] == 5) {
                ++f1 ;
            } else if (bills[i] == 10) {
                if (f1 == 0) {
                    return false ;
                }
                --f1 ; ++f2 ;
            } else {
                if (f1 > 0 && f2 > 0) {
                    --f1 ; --f2 ;
                } else if (f1 > 2) {
                    f1 -= 3 ;
                } else return false ;
            }
        }
        return true ;
    }
};