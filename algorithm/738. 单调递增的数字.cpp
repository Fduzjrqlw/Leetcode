class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string s = to_string(N) ;
        int n = s.length() ;
        if (N == 0) {
            return 0 ;
        }
        int res = 0 , pos = 1 ;
        while (pos < n && s[pos - 1] <= s[pos]) {
            ++pos ;
        }
        while (pos > 0 && pos < n && s[pos - 1] > s[pos]) {
            s[pos - 1] = s[pos - 1] - 1 ;
            --pos ;
        }
        for (int i = 0 ; i <= min(pos , n - 1) ; ++i) {
            res = res * 10 + (s[i] - '0') ;
        }
        for (int i = pos + 1; i < n ; ++i) {
            res = res * 10 + 9 ;
        }
        return res ;
    }
};