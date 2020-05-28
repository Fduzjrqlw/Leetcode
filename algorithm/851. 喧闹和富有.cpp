class Solution {
public:
    bool vis[501] ;

    void dp(int u , vector<int>& res , vector<vector<int>>& g, vector<int>& quiet) {
        vis[u] = true ;
        res[u] = u ;
        for (int i = 0 ; i < g[u].size() ; ++i) {
            int v = g[u][i] ;
            if (!vis[v]) {
                dp(v , res , g , quiet) ;
            }
            if (quiet[res[v]] <= quiet[res[u]]) {
                res[u] = res[v] ;
            }
        }
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size() ;
        vector<int> res(n , 0) ;
        vector<vector<int>> g(n) ;
        memset(vis , false , sizeof(vis)) ;

        for (int i = 0 ; i < richer.size() ; ++i) {
            //cout << richer[i][1] << " " << richer[i][0] << endl ;
            g[richer[i][1]].push_back(richer[i][0]) ;
        }

        for (int i = 0 ; i < n ; ++i) {
            if (!vis[i]) {
                dp(i , res , g , quiet) ;
            }
        }
        return res ;
    }
};