class Solution {
public:

    const int dx[4] = {0 , 1 , 0 , -1} ;
    const int dy[4] = {1 , 0 , -1 , 0} ;

    bool vis[50][50] ; 
    int N , M , cnt ;

    void dfs(int x , int y , vector<vector<int>>& grid) {
        vis[x][y] = true ;
        ++cnt ;
        for (int d = 0 ; d < 4 ; ++d) {
            int nx = x + dx[d] , ny = y + dy[d] ;
            if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
                if (grid[nx][ny] == 1 && !vis[nx][ny]) {
                    dfs(nx , ny , grid) ;
                }
            }
        }
    }

    int work(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size() ;
        memset(vis , false , sizeof(vis)) ;
        int  ans = 0 ;
        for (int i = 0 ; i < m ; ++i) {
            for (int j = 0 ; j < n ; ++j) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    cnt = 0 ;
                    dfs(i , j , grid) ;
                    ans = max(ans , cnt) ;
                }
            }
        }
        return ans ;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int res = 0 ;
        M = grid.size() , N = grid[0].size() ;
        res = work(grid) ;
        for (int i = 0 ; i < M ; ++i) {
            for (int j = 0 ; j < N ; ++j) {
                if (grid[i][j] == 1)
                    continue ;
                grid[i][j] = 1 ;
                res = max(res , work(grid)) ;
                grid[i][j] = 0 ;
            }
        }
        return res ;
    }
};