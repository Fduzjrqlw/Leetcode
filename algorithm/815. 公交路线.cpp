class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if (S == T)
            return 0 ;
        vector<bool> visRoutes(500 , false) ;
        vector<vector<int>> vecToRoute(1000000) ;
        vector<bool> visVec(1000000 , false) ;
        vector<int> dis(1000000) ;

        for (int i = 0 ; i < routes.size() ; ++i) {
            for (int j = 0 ; j < routes[i].size() ; ++j) {
                vecToRoute[routes[i][j]].push_back(i) ;
            }
        }

        queue<int> q ;

        visVec[S] = true ;
        q.push(S) ;
        dis[S] = 0 ;

        while (!q.empty()) {
            int u = q.front() ; q.pop() ;
            if (u == T) {
                return dis[T] ;
            }
            for (int i = 0 ; i < vecToRoute[u].size() ; ++i) {
                int roid = vecToRoute[u][i] ;
                if (visRoutes[roid]) continue  ;
                visRoutes[roid] = true ;
                for (int j = 0 ; j < routes[roid].size() ; ++j) {
                    int v = routes[roid][j] ;
                    if (visVec[v]) continue ;
                    dis[v] = dis[u] + 1 ;
                    visVec[v] = true ;
                    q.push(v) ;
                }
            }
        }

        return -1 ;
    }
};