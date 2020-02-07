class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<pair<int,int>>> G(N + 1) ;
        for (int i = 0 ; i < times.size() ; ++i) {
            G[times[i][0]].push_back(make_pair(times[i][1] , times[i][2])) ;
        }
        queue<int> q ;
        vector<int> dist(N + 1 , 0x7f7f7f) ; 
        vector<bool> vis(N + 1 , false) ;
        vis[K] = true ;
        dist[K] = 0 ;
        q.push(K) ;
        while (!q.empty()) {
            int u = q.front() ; q.pop() ;
            vis[u] = false ;
            for (int i = 0 ; i < G[u].size() ; ++i) {
                int v = G[u][i].first , w = G[u][i].second ;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w ;
                    if (!vis[v]) {
                        q.push(v) ;
                        vis[v] = true ;
                    }
                }
            }
        }
        int res = 0 ;
        for (int i = 1 ; i <= N ; ++i) {
            res = max(res , dist[i]) ;
        }
        cout << endl ;
        if (res == 0x7f7f7f) {
            return -1 ;
        }
        return res ;
    }
};