class Solution {
public:
    string decodeAtIndex(string S, int K) {
        int l = S.length() ;
        string res = "" ;
        long long s = 0ll ;
        for (int i = 0 ; i < l ; ++i) {
            if (S[i] >= 'a' && S[i] <= 'z') {
                ++s ;
            } else if (S[i] >= '2' && S[i] <= '9') {
                int d = S[i] - '0' ;
                s = s * d ;
            }
        }

        for (int i = l - 1 ; i >= 0 ; --i) {
            K = K % s ;
            if (K == 0 && (S[i] >= 'a' && S[i] <= 'z')) {
                res = S[i] ;
                return res ;
            }
            if (S[i] >= 'a' && S[i] <= 'z') {
                --s ;
            } else {
                int d = S[i] - '0' ;
                s = s / d ;
            }
        }
        return "" ;
    }
};