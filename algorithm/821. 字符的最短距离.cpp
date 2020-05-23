class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int n = S.length() ;
        vector<int> res (n , 0x7f7f7f) , pos ;
        pos.push_back(-0x7f7f7f) ;
        for (int i = 0 ; i < n ; ++i) {
            if (S[i] == C) {
                pos.push_back(i) ;
            }
        }
        pos.push_back(0x7f7f7f7f) ;

        int p = 0 ;

        for (int i = 0 ; i < n ; ++i) {
            if (i > pos[p + 1]) {
                ++p ;
            }
            res[i] = min(abs(i - pos[p]) , abs(i - pos[p + 1])) ;
        }
        return res ;
    }
};