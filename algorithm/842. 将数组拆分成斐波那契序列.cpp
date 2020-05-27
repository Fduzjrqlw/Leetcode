class Solution {
public:
    vector<int> res ;

    bool check(int f1 , int f2 , string &S) {
        long long x = 0ll ;
        for (int i = 0 ; i <= f1 ; ++i) {
            x = x * 10 + (S[i] - '0') ;
        }
        long long y = 0ll ;
        for (int i = f1 + 1 ; i <= f2 ; ++i) {
            y = y * 10 + (S[i] - '0') ;
        }
        
        string t1 = to_string(x) ;
        if (t1.length() != f1 + 1)
            return false ;
        string t2 = to_string(y) ;
        if (t2.length() != (f2 - f1))
            return false ;
        //cout << x << " " << y << endl ;
        if (f1 >= (long long) INT_MAX)
            return false ;
        if (f2 >= (long long) INT_MAX)
            return false ;
        
        int p = f2 + 1 ;
        vector<int> temp ;
        temp.push_back(x) ;
        temp.push_back(y) ;
        
        
        while (true) {
            long long z = x + y ;
            if (z >= (long long) INT_MAX)
                return false ;
            string t = to_string(z) ;
            temp.push_back(z) ;
            if (p + t.length() > S.length()) {
                return false ;
            }
            for (int i = 0 ; i < t.length() ; ++i) {
                if (t[i] != S[p + i]) {
                    return false ;
                }
            }
            p = p + t.length() ;
            if (p >= S.length()) {
                break ;
            }
            x = y ;
            y = z ;
        }
        if (p == S.length()) {
            res = temp ;
            return true ;
        }
        return false ;
    }
    vector<int> splitIntoFibonacci(string S) {
        int l = S.length() ;
        for (int i = 0 ; i + 2 < S.length() ; ++i) {
            if (i >= 11) {
                continue ;
            }
            for (int j = i + 1 ; j + 1 < S.length() ; ++j) {
                if (j - i >= 11) {
                    continue ;
                }
                if (check(i , j , S)) {
                    return res ;
                }
            }
            
        }
        return res ;
    }
};