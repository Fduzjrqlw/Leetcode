class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size() ;
        if (n == 0) {
            return "" ;
        }
        string res = dominoes ;
        vector<int> ids ;
        vector<char> ops ;
        ids.push_back(-1) ;
        ops.push_back('L') ;
        for (int i = 0 ; i < n ; ++i) {
            if (dominoes[i] != '.') {
                ids.push_back(i) ;
                ops.push_back(dominoes[i]) ;
            }
        }
        ids.push_back(n) ;
        ops.push_back('R') ;
        for (int i = 0 ; i < ids.size() - 1 ; ++i) {
            char x = ops[i] , y = ops[i + 1] ;
            int l = ids[i] , r = ids[i + 1] ;
            if (x == y) {
                for (int j = l + 1 ; j < r ; ++j) {
                    res[j] = x ;
                }
            } else {
                if (x < y) {
                    for (int j = l + 1 ; j < r ; ++j) {
                        res[j] = '.' ;
                    }
                } else {
                    for (int j = l + 1 ; j < r ; ++j) {
                        if (j - l == r - j) {
                            res[j] = '.' ;
                        } else if (j - l < r - j) {
                            res[j] = 'R' ;
                        } else res[j] = 'L' ;
                    }
                }
            }
        }
        return res ;
    }
};