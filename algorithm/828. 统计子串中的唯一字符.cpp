class Solution {
public:

    typedef long long ll ;
    ll module = 1e9 + 7 ;
    int uniqueLetterString(string s) {
        int n = s.length() ;
        ll res = 0ll ;
        vector<vector<int>> pos(26) ;
        for (int i = 0 ; i < n ; ++i) {
            pos[s[i] - 'A'].push_back(i) ;
        }
        for (int c = 0 ; c < 26 ; ++c) {
            if (pos[c].size() == 0) {
                continue ;
            }
            if (pos[c].size() == 1) {
                res = (res + (1 + pos[c][0] - 0) * (1 + n - 1 - pos[c][0]) % module) % module ;
            }
            if (pos[c].size() == 2) {
                int k = pos[c].size() ;
                res = (res + (1 + pos[c][0] - 0) * (1 + pos[c][1] - pos[c][0] - 1) % module) % module ;
                res = (res + (1 + pos[c][k - 1] - pos[c][k - 2] - 1) * (1 + n - 1 - pos[c][k - 1]) % module) % module ;
            }
            if (pos[c].size() > 2) {
                int k = pos[c].size() ;
                res = (res + (1 + pos[c][0] - 0) * (1 + pos[c][1] - pos[c][0] - 1) % module) % module ;
                res = (res + (1 + pos[c][k - 1] - pos[c][k - 2] - 1) * (1 + n - 1 - pos[c][k - 1]) % module) % module ;
                for (int j = 1 ; j + 1 < k ; ++j) {
                    res = (res + (1 + pos[c][j] - pos[c][j - 1] - 1) * (1 + pos[c][j + 1] - pos[c][j] - 1) % module) % module ;
                }
            }
        }
        return res ;
    }
};