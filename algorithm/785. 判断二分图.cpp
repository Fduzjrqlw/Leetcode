class Solution {
public:

    void dfs(int u , vector<vector<int>>& graph , vector<int> &color , bool &res , int c) {
        color[u] = c ;
        for (int i = 0 ; i < graph[u].size() ; ++i) {
            int v = graph[u][i] ;
            if (!color[v]) {
                dfs(v , graph , color , res , 3 - c) ;
            } else if (color[v] == color[u]) {
                res = false ;
                return ;
            }
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size() ;
        bool res = true ;
        vector<int> color(n , 0) ;
        for (int i = 0 ; i < n ; ++i) {
            if (color[i] == 0) {
                dfs(i , graph , color , res , 1) ;
            }
        }
        return res ;
    }
};