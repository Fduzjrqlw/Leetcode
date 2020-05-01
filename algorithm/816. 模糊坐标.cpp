class Solution {
public:

    vector<string> generate(string &T) {
        vector<string> res ;
        if (T.length() == 1 || (T[0] != '0')) {
            res.push_back(T) ;
        }

        for (int i = 1 ; i < T.length() ; ++i) {
            if (i == 1 || (T[0] != '0')) {
                string temp = "" ;
                if (T[T.length() - 1] != '0') {
                    for (int j = 0 ; j < i ; ++j) {
                        temp += T[j] ;
                    }
                    temp += '.' ;
                    for (int j = i ; j < T.length() ; ++j) {
                        temp += T[j] ;
                    }
                    res.push_back(temp) ;
                }
            }
        }
        return res ;
    }

    vector<string> ambiguousCoordinates(string S) {
        int n = S.length() ;
        vector<string> res ;

        for (int i = 1 ; i + 2 < n ; ++i) {
            string l = "" , r = "" ;
            for (int j = 1 ; j <= i ; ++j) {
                l += S[j] ;
            }
            for (int j = i + 1 ; j + 1 < n ; ++j) {
                r += S[j] ;
            }
            vector<string> resl , resr ;
            resl = generate(l) ;
            resr = generate(r) ;
            for (int ll = 0 ; ll < resl.size() ; ++ll) {
                for (int rr = 0 ; rr < resr.size() ; ++rr) {
                    string temp = "" ;
                    temp += "(" ;
                    temp += resl[ll] ;
                    temp += ", " ;
                    temp += resr[rr] ;
                    temp += ")" ;
                    res.push_back(temp) ;
                }
            }
        }
        return res ;
    }
};