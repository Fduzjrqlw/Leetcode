class Solution {
public:

    int calc(int l , int r , string &S) {
        if (l + 1 == r) {
            return 1 ;
        }
        int cnt = 1 , k = l + 1 ;
        for (k = l + 1 ; k <= r ; ++k) {
            if (S[k] == '(') {
                ++cnt ;
            } else --cnt ;
            if (cnt == 0) {
                break ;
            }
        }
        if (k == r) {
            return 2 * calc(l + 1 , r - 1 , S) ;
        }
        return calc(l , k , S) + calc(k + 1 , r , S) ;
    }

    int scoreOfParentheses(string S) {
        return calc(0 , S.length() - 1 , S) ;
    }
};