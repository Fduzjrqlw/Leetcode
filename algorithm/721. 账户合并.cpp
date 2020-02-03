class Solution {
public:

    void dfs(string s , unordered_map<string,unordered_map<string , int>>& edge , unordered_map<string,int>& vis , int cnt) {
        vis[s] = cnt ;
        for (auto t : edge[s]) {
            if (vis.find(t.first) == vis.end()) {
                dfs(t.first , edge , vis , cnt) ;
            }
        }
    }


    static bool cmp(const string& A , const string& B) {
        return A > B ;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size() ;
        unordered_map<string,string> mails ;
        unordered_map<string,unordered_map<string , int>> edge ;
        unordered_map<string,int> vis ;

        for (int i = 0 ; i < n ; ++i) {
            for (int j = 1 ; j < accounts[i].size() ; ++j) {
                mails[accounts[i][j]] = accounts[i][0] ;
                edge[accounts[i][1]][accounts[i][j]] = 1 ;
                edge[accounts[i][j]][accounts[i][1]] = 1 ;
            }
        }

        int cnt = 0 ;
        for (auto v : edge) {
            if (vis.find(v.first) == vis.end()) {
                ++cnt ; 
                dfs(v.first , edge , vis , cnt) ;
            }
        }
        vector<vector<string>> res(cnt);
        for (auto v : vis) {
            res[v.second - 1].push_back(v.first) ;
        }
        for (int i = 0 ; i < cnt; ++i) {
            sort(res[i].begin() , res[i].end() , cmp) ;
            res[i].push_back(mails[res[i][0]]) ;
            reverse(res[i].begin() , res[i].end()) ;
        }

        return res ;
    }
};