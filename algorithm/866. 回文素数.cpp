class Solution {
public:
    int res ;
    bool check(int x) {
        if (x == 1)
            return false ;
        if (x == 2)
            return true ;
        string S = to_string(x) ;
        if (S.length() > 1 && ((S[0] - '0') % 2 == 0 || S[0] == '5'))
            return false ;
        for (int i = 0 ; i < S.length() ; ++i) {
            if (S[i] != S[S.length() - 1 - i]) {
                return false ;
            }
        }
        for (int y = 2 ; y * y <= x ; ++y) {
            if (x % y == 0)
                return false ;
        }
        return true ;
    }

    void generate(int pos , int len , int N , vector<int>& temp , int start) {
        if (pos * 2 >= len) {
            for (int i = len - 1 ; i >= pos ; --i) {
                temp[i] = temp[len - 1 - i] ;
            }
            int x = 0 ;
            for (int i = 0 ; i < temp.size() ; ++i) {
                x = x * 10 + temp[i] ;
            }
            if (x >= N && check(x)) {
                res = min(res , x) ;
            }
            return ;
        }
        if (pos == 0) {
            for (int i = start ; i <= 9 ; ++i) {
                if (i % 2 == 0 || i == 5) continue ;
                temp[pos] = i ;
                generate(pos + 1 , len , N , temp , start) ;
                temp[pos] = 0 ;
            }
        } else {
            for (int i = 0 ; i <= 9 ; ++i) {
                temp[pos] = i ;
                generate(pos + 1 , len , N , temp , start) ;
                temp[pos] = 0 ;
            }
        }
    }

    int primePalindrome(int N) {
        string S = to_string(N) ;

        if (N <= 100000) {
            int x = N ;
            while (true) {
                if (check(x)) {
                    return x ;
                }
                ++x ;
            }
        } else {
            res = INT_MAX ;
            for (int len = S.length() ; len <= 9 ; ++len) {
                if (len == 8)
                    continue ;
                vector<int> temp(len , 0) ;
                generate(0 , len , N , temp , 0) ;
                if (res != INT_MAX)
                    return res ;
            }
        }
        return res ;
    }
};