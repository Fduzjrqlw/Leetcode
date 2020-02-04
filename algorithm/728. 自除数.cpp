class Solution {
public:

    bool check(int x) {
        if (x == 0) {
            return false ;
        }
        int y = x ;
        while (y) {
            if (y  % 10 == 0) {
                return false ;
            }
            if (x % (y % 10) != 0) {
                return false ;
            }
            y /= 10 ;
        }
        return true ;
    }

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res ;
        for (int i = left ; i <= right ; ++i) {
            if (check(i)) {
                res.push_back(i) ;
            }
        }
        return res ;
    }
};