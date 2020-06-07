class Solution {
public:

    vector<vector<int>> G ;
    vector<int> color ;
    bool res ;

    void dfs(int u , int c) {
        color[u] = c ;
        for (int i = 0 ; i < G[u].size() ; ++i) {
            int v = G[u][i] ;
            if (color[v] == 0) {
                dfs(v , 3 - c) ;
            }
            if (color[v] == color[u]) {
                res = false ;
            }
        }
    }

    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        G = vector<vector<int>> (N + 1) ;
        color = vector<int> (N + 1) ;
        res = true ;

        for (int i = 0 ; i < dislikes.size() ; ++i) {
            G[dislikes[i][0]].push_back(dislikes[i][1]) ;
            G[dislikes[i][1]].push_back(dislikes[i][0]) ;
        }

        for (int i = 1 ; i <= N ; ++i) {
            if (color[i] == 0) {
                dfs(i , 1) ;
            }
        }

        return res ;


    }
};