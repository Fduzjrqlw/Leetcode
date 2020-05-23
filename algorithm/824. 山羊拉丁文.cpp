class Solution {
public:
    string toGoatLatin(string S) {
        vector<string> words ;
        int p = 0 ;
        string t = "" ;
        unordered_map<char,int> inlist ;
        inlist['a'] = 1 ; inlist['e'] = 1 ; inlist['i'] = 1 ; inlist['o'] = 1 ;
        inlist['u'] = 1 ; inlist['A'] = 1 ; inlist['E'] = 1 ; inlist['I'] = 1 ;
        inlist['O'] = 1 ; inlist['U'] = 1 ;
        while (p < S.length()) {
            if (S[p] == ' ') {
                words.push_back(t) ;
                t = "" ;
                ++p ;
            }
            t += S[p++] ;
            if (p == S.length()) {
                words.push_back(t) ;
            }
        }
        string res = "" ;
        for (int i = 0 ; i < words.size() ; ++i) {
            if (inlist[words[i][0]] == 1) {
                res += words[i] ;
                res += "ma" ;
            } else {
                res += words[i].substr(1) ;
                res += words[i][0] ;
                res += "ma" ;
            }
            for (int j = 0 ; j <= i ;  ++j) {
                res += 'a' ;
            }
            if (i + 1 != words.size()) {
                res += " " ;
            }
        }
        return res ;
    }
};