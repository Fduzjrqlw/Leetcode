class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int res = 0 ;
        for (int d = 1 ; d <= sqrt(2 * N) + 1 ; ++d) {
            if (2 * N % d == 0) {
                int l = 2 * N / d + 1 - d ;
                if (l % 2 == 0 && l > 0) {
                    ++res ;
                }
            }
        }
        return res ;
    }
};