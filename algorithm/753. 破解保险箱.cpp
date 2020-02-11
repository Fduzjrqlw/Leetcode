class Solution {
public:
    unordered_map<string,int> vis ;
    string res ;

    void dfs(string s , int k , int n) {
        for (int i = 0 ; i < k ; ++i) {
            string t = s ;
            t += ('0' + i) ;
            if (vis.find(t) == vis.end()) {
                vis[t] = 1 ;
                dfs(t.substr(1) , k , n) ;
                res += (i + '0') ;
            }
        }
    }
    string crackSafe(int n, int k) {
        if (k == 1) {
            for (int i = 0 ; i < n ; ++i) {
                res += '0' ;
            }
            return res ;
        }
        string temp = "" ;
        for (int i = 0 ; i < n - 1 ; ++i) {
            temp += '0' ;
        }
        dfs(temp , k , n) ;
        for (int i = 0 ; i < n - 1 ; ++i) {
            res += '0' ;
        }
        return res ;
    }
};