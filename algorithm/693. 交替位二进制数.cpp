class Solution {
public:
    bool hasAlternatingBits(int n) {
        long long m = n ^ (n >> 1) ;
        if ((m & ((m + 1))) == 0)
            return true ;
        return false ;
    }
};