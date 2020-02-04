class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> res ;
        string temp = "" ;
        int state = 0 ;
        //state 0 当前没在注释里
        //state 1 当前在行注释里
        //state 2 当前在块注释里
        for (int i = 0 ; i < source.size() ; ++i) {
            bool empty = false ;
            for (int j = 0 ; j < source[i].length() ; ) {
                if (state == 0) {
                    if (source[i][j] == '/') {
                        if (j + 1 < source[i].length() && source[i][j + 1] == '/') {
                            state = 1 ;
                            j+= 2 ;
                        } else if (j + 1 < source[i].length() && source[i][j + 1] ==  '*') {
                            state = 2 ;
                            j += 2 ;
                        } else {
                            temp += source[i][j] ;
                            ++j ;
                        }
                    } else {
                        temp += source[i][j] ;
                        ++j ;
                    }
                } else if (state == 1) {
                    ++j ;
                } else if (state == 2) {
                    if (source[i][j] == '*') {
                        if (j + 1 < source[i].length() && source[i][j + 1] == '/') {
                            state = 0 ;
                            j += 2 ;
                        } else {
                            ++j ;
                        }
                    } else {
                        ++j ;
                    }
                }
            }
            int l = source[i].length() ;
            if (temp == "" && (state == 2 || (source[i].length() >= 2 && source[i][l - 1] == '/' && source[i][l - 2] == '*'))) {
                empty = true ;
            }
            if (temp == "" && state == 1) {
                empty = true ;
            }
            if (!empty && state != 2) {
                res.push_back(temp) ;
            }
            if (state == 1) {
                state = 0 ;
            }
            if (state != 2) {
                temp = "" ;
            }
        }
        return res ;
    }
};