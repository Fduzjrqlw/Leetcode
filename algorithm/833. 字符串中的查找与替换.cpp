class Solution {
public:

    struct Op {
        int id ;
        string source , target ;
    } ;

    static bool cmp(const Op &a , const Op &b) {
        return a.id < b.id ;
    }

    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        vector<Op> ops ;
        for (int i = 0 ; i < indexes.size() ; ++i) {
            ops.push_back({indexes[i] , sources[i] , targets[i]}) ;
        }
        sort(ops.begin() , ops.end() , cmp) ;
        string res = "" ;

        int p = 0 ;
        for (int i = 0 ; i < S.length() ; ) {
            if (p >= ops.size() || i < ops[p].id) {
                res += S[i] ;
                ++i ;
            } else {
                bool flag = true ;
                if (S.length() - ops[p].id < ops[p].source.length()) {
                    flag = false ;
                }
                if (flag)
                for (int j = 0 ; j < ops[p].source.length() ; ++j) {
                    if (S[j + ops[p].id] != ops[p].source[j]) {
                        flag = false ;
                        break ;
                    }
                }
                
                if (!flag) {
                    ++p ;
                } else {
                    res += ops[p].target ;
                    i = i + ops[p].source.length() ;
                    ++p ;
                }
            }
        }
        return res ;
    }
};