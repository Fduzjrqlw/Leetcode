class Solution {
public:


    string mail(string &S) {
        string res = "" ;
        int p = 0 ;
        for (int i = 0 ; i < S.length() ; ++i) {
            if (S[i] >= 'A' && S[i] <= 'Z') {
                S[i] = S[i] - 'A' + 'a' ;
            }
            if (S[i] == '@') {
                p = i ;
            }
        }

        res = S[0] ;
        res += "*****" ;
        res += S[p - 1] ;
        res += S.substr(p) ;
        return res ;
    }

    string phone(string &S) {
        int cnt = 0 ;
        for (int i = 0 ; i < S.length() ; ++i) {
            if (S[i] >= '0' && S[i] <= '9') {
                ++cnt ;
            }
        }
        string temp = "" ;
        int t = 4 ;
        for (int i = S.length() - 1 ; i >= 0 ; --i) {
            if (S[i] >= '0' && S[i] <= '9') {
                temp += S[i] ;
                --t ;
            }
            if (t == 0) {
                break ;
            }
        }
        reverse(temp.begin() , temp.end()) ;
        string res = "" ;
        if (cnt == 10) {
            res = "***-***-" + temp ;
        } else {
            res = "+" ;
            for (int i = 1 ; i <= cnt - 10 ; ++i) {
                res += "*" ;
            }
            res += "-***-***-" + temp ;
        }
        return res ;
    }

    string maskPII(string S) {
        bool ismail = false ;
        for (int i = 0 ; i < S.length() ; ++i) {
            if (S[i] == '@') {
                ismail = true ;
                break ;
            }
        }
        if (ismail) {
            return mail(S) ;
        }
        return phone(S) ;
    }
};