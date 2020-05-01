class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string,int> ban ;
        unordered_map<string,int> count ;
        string temp = "" ;

        for (int i = 0 ; i < banned.size() ; ++i) {
            for (int j = 0 ; j < banned[i].length() ; ++j) {
                if (banned[i][j] >= 'A' && banned[i][j] <= 'Z') {
                    banned[i][j] = banned[i][j] - 'A' + 'a' ;
                }
            }
            ban[banned[i]] = 1 ;
        }
        temp = "" ;

        int p = 0 ;
        while (p < paragraph.length()) {
            if (!((paragraph[p] >= 'a' && paragraph[p] <= 'z') || (paragraph[p] >= 'A' && paragraph[p] <= 'Z'))) {
                temp = "" ;
                ++p ;
                continue ;
            }
            while (p < paragraph.length() && ((paragraph[p] >= 'a' && paragraph[p] <= 'z') || (paragraph[p] >= 'A' && paragraph[p] <= 'Z'))) {
                if (paragraph[p] >= 'A' && paragraph[p] <= 'Z')
                    temp += (paragraph[p] - 'A' + 'a') ;
                else temp += paragraph[p] ;
                ++p ;
            }
            count[temp]++ ;
        }
        string res = "" ;
        int m = 0 ;
        for (auto pr : count) {
            if (ban.find(pr.first) == ban.end()) {
                if (pr.second > m) {
                    m = pr.second ;
                    res = pr.first ;
                }
            }
        }
        return res ;

    }
};