class Solution {
public:
    string longestWord(vector<string>& words) {
        string res = "" ;
        int n = words.size() ;
        sort(words.begin() , words.end()) ;
        vector<int> dp(n , -1) ;
        for (int i = 0 ; i < n ; ++i) {
            if (words[i].length() == 1) {
                dp[i] = 1 ;
            } else {
                for (int j = 0 ; j < i ; ++j) {
                    if (words[i].length() == words[j].length() + 1) {
                        bool renew = true ;
                        for (int k = 0 ; k < words[j].length() ; ++k) {
                            if (words[i][k] != words[j][k]) {
                                renew = false ;
                                break ;
                            }
                        }
                        if (renew && dp[j] != -1) {
                            dp[i] = dp[j] + 1 ;
                            break ;
                        }
                    }
                }
            }
        }
        for (int i = 0 ; i < n ; ++i) {
            if (dp[i] != -1) {
                if (words[i].length() > res.length()) {
                    res = words[i] ;
                }
                if (words[i].length() == res.length()) {
                    if (words[i] < res) {
                        res = words[i] ;
                    }
                }
            }
        }
        return res ;
    }
};