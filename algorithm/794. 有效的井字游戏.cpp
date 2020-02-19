class Solution {
public:
    char g[3][3] ;

    bool check(char c) {
        bool win = false ;
        for (int i = 0 ; i < 3 ; ++i) {
            bool flag = true ;
            for (int j = 0 ; j < 3 ; ++j) {
                if (g[i][j] != c) {
                    flag = false ;
                }
            }
            if (flag) {
                return true ;
            }
        }
        for (int i = 0 ; i < 3 ; ++i) {
            bool flag = true ;
            for (int j = 0 ; j < 3 ; ++j) {
                if (g[j][i] != c) {
                    flag = false ;
                }
            }
            if (flag) {
                return true ;
            }
        }
        if (g[0][0] == c && g[1][1] == c && g[2][2] == c) {
            return true ;
        }
        if (g[0][2] == c && g[1][1] == c && g[2][0] == c) {
            return true ;
        }
        return false ;
    }

    bool validTicTacToe(vector<string>& board) {
        for (int i = 0 ; i < board.size() ; ++i) {
            for (int j = 0 ; j < board[i].length() ; ++j) {
                g[i][j] = board[i][j] ;
            }
        }
        int x = 0 , o = 0 ;
        for (int i = 0 ; i < 3 ; ++i) {
            for (int j = 0 ; j < 3 ; ++j) {
                if (g[i][j] == 'O') {
                    ++o ;
                } else if (g[i][j] == 'X') {
                    ++x ;
                }
            }
        }
        //rule1
        if (x < o || x > o + 1) {
            return false ;
        }
        bool xwin = false , owin = false ;
        xwin = check('X') ;
        owin = check('O') ;
        if (xwin && owin) {
            return false ;
        }
        if (xwin && x == o) {
            return false ;
        }
        if (owin && x == o + 1) {
            return false ;
        }
        return true ;
    }
};