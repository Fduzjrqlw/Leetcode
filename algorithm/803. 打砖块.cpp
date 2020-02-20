class Solution {
public:

    const int dx[4] = {0 , 1 , 0 , -1} ;
    const int dy[4] = {1 , 0 , -1 , 0} ;
    int f[200 * 200 + 100] , sz[200 * 200 + 100] ;

    int findSet(int u) {
        int v = u ;
        while (v != f[v]) {
            v = f[v] ;
        }
        while (u != f[u]) {
            int t = f[u] ;
            f[u] = v ;
            u = t ;
        }
        return u ;
    }

    void unionSet(int u , int v) {
        u = findSet(u) ; v = findSet(v) ;
        if (u == v) 
            return ;
        if (rand() & 1) {
            f[v] = u ;
            sz[u] += sz[v] ;
        } else {
            f[u] = v ;
            sz[v] += sz[u] ;
        }
        return ;
    }

    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m = grid.size() , n = grid[0].size() ;
        vector<vector<int>> finalGrid = grid ;
        vector<int> res ;
        for (int i = 0 ; i < hits.size() ; ++i) {
            finalGrid[hits[i][0]][hits[i][1]] = 0 ;
        }
        for (int i = 0 ; i < m ; ++i) {
            for (int j = 0 ; j < n ; ++j) {
                f[i * n + j] = i * n + j ;
                sz[i * n + j] = finalGrid[i][j] ;
            }
        }

        f[m * n] = m * n ;
        sz[m * n] = 0 ;
        
        for (int i = 0 ; i < n ; ++i) {
            if (finalGrid[0][i] == 1) {
                unionSet(i , n * m) ;
            }
        }


        for (int i = 1 ; i < m ; ++i) {
            for (int j = 0 ; j < n ; ++j) {
                if (finalGrid[i][j] == 0)
                    continue ;
                if (j > 0 && finalGrid[i][j - 1] == 1) {
                    unionSet(i * n + j - 1 , i * n + j) ;
                }
                if (finalGrid[i - 1][j] == 1) {
                    unionSet((i - 1) * n + j , i * n + j) ;
                }
            }
        }

        int times = hits.size() ;
        for (int i = times - 1 ; i >= 0 ; --i) {
            int num = sz[findSet(n * m)] ;
            if (grid[hits[i][0]][hits[i][1]] == 0) {
                res.push_back(0) ;
                continue ;
            }
            sz[hits[i][0] * n + hits[i][1]] = 1 ;
            for (int k = 0 ; k < 4 ; ++k) {
                int x = hits[i][0] + dx[k] , y = hits[i][1] + dy[k] ;
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    if (finalGrid[x][y] > 0) {
                        unionSet(hits[i][0] * n + hits[i][1] , x * n + y) ;
                    }
                }
            }
            if (hits[i][0] == 0) {
                unionSet(hits[i][0] * n + hits[i][1] , n * m) ;
            }
            finalGrid[hits[i][0]][hits[i][1]] = 1 ;
            res.push_back(max(0 , sz[findSet(n * m)] - num - 1)) ;
        }
        if (res.size() > 0)
            reverse(res.begin() , res.end()) ;
        
        return res ;
    }
};