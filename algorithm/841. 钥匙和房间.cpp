class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size() ;
        queue<int> q ;
        vector<bool> vis(n , false) ;
        vis[0] = true ;
        q.push(0) ;

        while (!q.empty()) {
            int u = q.front() ; q.pop() ;
            for (int i = 0 ; i < rooms[u].size() ; ++i) {
                int v = rooms[u][i] ;
                if (!vis[v]) {
                    q.push(v) ;
                    vis[v] = true ;
                }
            }
        }
        for (int i = 0 ; i < n ; ++i) {
            if (!vis[i]) {
                return false ;
            }
        }
        return true ;
    }
};