class Solution {
public:

    const int dx[4] = {1 , 0 , -1 , 0} ;
    const int dy[4] = {0 , 1 , 0 , -1} ;
    void dfs(int x , int y , int m , int n , vector<vector<int>>& grid , vector<vector<bool>>& vis , int& cnt) {
        vis[x][y] = true ;
        ++cnt ;
        for (int d = 0 ; d < 4 ; ++d) {
            if (x + dx[d] >= 0 && x + dx[d] < m && y + dy[d] >= 0 && y + dy[d] < n) {
                if ((!vis[x + dx[d]][y + dy[d]]) && grid[x + dx[d]][y + dy[d]] == 1) {
                    dfs(x + dx[d] , y + dy[d] , m , n , grid , vis , cnt) ;
                }
            }
        }
        return ;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size() ;
        vector<vector<bool>> vis(m , vector<bool> (n , false)) ;
        int res = 0 ;
        for (int i = 0 ; i < m ; ++i) {
            for (int j = 0 ; j < n ; ++j) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    int cnt = 0 ;
                    dfs(i , j , m , n , grid , vis , cnt) ;
                    res = max(res , cnt) ;
                }
            }
        }
        return res ;
    }
};