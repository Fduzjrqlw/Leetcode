class Solution {
public:
    int countBinarySubstrings(string s) {
        if (s.length() <= 1) {
            return 0 ;
        }
        char last_token = 1 - (s[0] - '0') + '0' ;
        int res = 0 , last_length = 0 , now_length = 0 ;
        for (int i = 0 ; i < s.length() ; ++i) {
            if (s[i] == last_token) {
                now_length++ ;
            } else {
                last_token = s[i] ;
                res += min(last_length , now_length) ;
                last_length = now_length ;
                now_length = 1 ;
            }
        }
        res += min(last_length , now_length) ;
        return res ;
    }
};