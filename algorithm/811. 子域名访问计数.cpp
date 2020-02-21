class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int> count ;
        vector<string> res ;
        for (int i = 0 ; i < cpdomains.size() ; ++i) {
            int j = 0 , x = 0 ;
            while (j < cpdomains[i].length() && cpdomains[i][j] != ' ') {
                x = x * 10 + (cpdomains[i][j] - '0') ;
                ++j ;
            }
            reverse(cpdomains[i].begin() , cpdomains[i].end()) ;
            string t = "" ;
            j = 0 ;
            while (j < cpdomains[i].length() && cpdomains[i][j] != ' ') {
                if (cpdomains[i][j] == '.') {
                    string s = t ;
                    reverse(s.begin() , s.end()) ;
                    count[s] += x ;
                }
                t += cpdomains[i][j] ;
                ++j ;
            }
            reverse(t.begin() , t.end()) ;
            count[t] += x ;
        }
        for (auto v : count) {
            res.push_back(to_string(v.second) + " " + v.first) ;
        }
        return res ;
    }
};

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int> count ;
        vector<string> res ;
        for (int i = 0 ; i < cpdomains.size() ; ++i) {
            int index = cpdomains[i].find(' ') ;
            int x = stoi(cpdomains[i].substr(0 , index)) ;
            string dmname = cpdomains[i].substr(index + 1) ;

            while (index > 0) {
                count[dmname] += x ;
                index = dmname.find('.') ;
                dmname = dmname.substr(index + 1) ;
            } 
        }

        for (auto v : count) {
            res.push_back(to_string(v.second) + " " + v.first) ;
        }

        return res ;
    }
};