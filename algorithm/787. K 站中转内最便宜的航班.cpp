class Solution {
public:

    struct node {
        int u , dis , k ;

        friend bool operator < (const node &A , const node &B) {
            return A.dis > B.dis ;
        }
    } ;

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        priority_queue<node> pq ;
        node state {src , 0 ,  0} ;
        vector<vector<int>> dist (n , vector<int> (n + 1 , 0x7f7f7f7f)) ;
        vector<vector<bool>> vis (n , vector<bool> (n + 1 , false)) ;
        dist[src][0] = 0 ;
        pq.push(state) ;

        vector<vector<vector<int>>> G(n) ;
        for (int i = 0 ; i < flights.size() ; ++i) {
            G[flights[i][0]].push_back({flights[i][1] , flights[i][2]}) ;
        }
        ++K ;

        while (!pq.empty()) {
            state = pq.top() ; pq.pop() ;
            int u = state.u , k = state.k;
            vis[u][k] = true ;
            for (int i = 0 ; i < G[u].size() ; ++i) {
                int v = G[u][i][0] , c = G[u][i][1] ;
                if (k + 1 <= K) {
                    if (dist[u][k] + c < dist[v][k + 1]) {
                        dist[v][k + 1] = dist[u][k] + c ;
                        if (!vis[v][k + 1]) {
                            pq.push({v ,  dist[v][k + 1] , k + 1}) ;
                        } 
                    }
                }
            }
        }
        int res = 0x7f7f7f7f ;
        for (int i = 0 ; i <= K ; ++i) {
            res = min(res , dist[dst][i]) ;
        }
        if (res == 0x7f7f7f7f)
            return -1 ;
        return res ;
    }
};