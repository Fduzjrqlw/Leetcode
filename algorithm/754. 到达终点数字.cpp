class Solution {
public:
    int reachNumber(int target) {
        target = abs(target) ;
        int k = 0 , s = 0 ;
        while (s < target) {
            s += ++k ;
        }
        int delta = s - target ;
        if (delta % 2 == 0) {
            return k ;
        }
        return k + 1 + k % 2 ;
    }
};