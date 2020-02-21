class Solution {
public:

    struct Group {
        char c ;
        int t ;
    } ;

    vector<Group> dense(string s) {
        vector<Group> res ;
        for (int i = 0 ; i < s.length() ; ++i) {
            if (i == 0 || s[i] != s[i - 1]) {
                res.push_back({s[i] , 0}) ;
            }
            ++res[res.size() - 1].t ;
        }
        return res ;
    }

    int expressiveWords(string S, vector<string>& words) {
        vector<Group> sg = dense(S) ;
        int res = 0 ;
        for (int i = 0 ; i < words.size() ; ++i) {
            vector<Group> temp = dense(words[i]) ;
            if (sg.size() != temp.size())
                continue ;
            for (int j = 0 ; j < sg.size() ; ++j) {
                if (sg[j].c != temp[j].c || sg[j].t < temp[j].t) {
                    --res ;
                    break ;
                }
                if (sg[j].t <= 2 && sg[j].t != temp[j].t) {
                    --res ;
                    break ;
                }
            }
            ++res ;
        }
        return res ;
    }
};