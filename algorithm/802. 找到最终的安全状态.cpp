class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> res ;
        int n = graph.size() ;
        vector<int> deg(n , 0) ;
        vector<vector<int>> invGraph(n) ;
        for (int i = 0 ; i < n ; ++i) {
            for (int j = 0 ; j < graph[i].size() ; ++j) {
                deg[i]++ ;
                invGraph[graph[i][j]].push_back(i) ;
            }
        }

        queue<int> q ;
        for(int i = 0 ; i < n ; ++i) {
            if (deg[i] == 0) {
                q.push(i) ;
            }
        }

        while (!q.empty()) {
            int u = q.front() ; q.pop() ;
            res.push_back(u) ;
            for (int i = 0 ; i < invGraph[u].size() ; ++i) {
                deg[invGraph[u][i]]-- ;
                if (deg[invGraph[u][i]] == 0) {
                    q.push(invGraph[u][i]) ;
                }
            }
        }
        if (res.size() > 0) {
            sort(res.begin() , res.end()) ;
        }
        return res ;
    }
};