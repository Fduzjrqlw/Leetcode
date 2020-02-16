class Solution {
public:
    vector<string> res ;

    void dfs(int pos , string &s , string &t) {
        if (pos == s.length()) {
            res.push_back(t) ;
        }
        if (s[pos] >= '0' && s[pos] <= '9') {
            t += s[pos] ;
            dfs(pos + 1 , s , t) ;
            t.pop_back() ;
        } else if (s[pos] >= 'A' && s[pos] <= 'Z') {
            t += s[pos] ;
            dfs(pos + 1 , s , t) ;
            t.pop_back() ;
            t += (s[pos] - 'A' + 'a') ;
            dfs(pos + 1 , s , t) ;
            t.pop_back() ;
        } else if (s[pos] >= 'a' && s[pos] <= 'z') {
            t += s[pos] ;
            dfs(pos + 1 , s , t) ;
            t.pop_back() ;
            t += (s[pos] - 'a' + 'A') ;
            dfs(pos + 1 , s , t) ;
            t.pop_back() ;
        }
    }
    vector<string> letterCasePermutation(string S) {
        res.clear() ;
        string start = "" ;
        dfs(0 , S , start) ;
        return res ;
    }
};