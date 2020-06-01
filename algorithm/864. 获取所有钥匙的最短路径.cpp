class Solution {
public:

    bool vis[64][31][31] ;
    char keys[7] ;
    int p[26] ;

    const int dx[5] = {0 , 1 , 0 , -1} ;
    const int dy[5] = {1 , 0 , -1 , 0} ;

    struct node {
        int s , x , y , d ;
    } ;

    int shortestPathAllKeys(vector<string>& grid) {
        int k = 0 , m = grid.size() , n = grid[0].size() , sx , sy ;
        for (int i = 0 ; i < m ; ++i) {
            for (int j = 0 ; j < n ; ++j) {
                if (grid[i][j] >= 'a' && grid[i][j] <= 'z') {
                    keys[k++] = grid[i][j] ;
                    p[grid[i][j] - 'a'] = k - 1 ;
                }
                if (grid[i][j] == '@') {
                    sx = i ; sy = j ;
                }
            }
        }

        vis[0][sx][sy] = true ;

        queue<node> q ;

        q.push({0 , sx , sy , 0}) ;

        while (!q.empty()) {
            node temp = q.front() ; q.pop() ;
            if (temp.s + 1 == (1 << k))
                return temp.d ;
            for (int d = 0 ; d < 4 ; ++d) {
                int nx = temp.x + dx[d] , ny = temp.y + dy[d] ;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    if (grid[nx][ny] == '.' || grid[nx][ny] == '@') {
                        if (!vis[temp.s][nx][ny]) {
                            vis[temp.s][nx][ny] = true ;
                            q.push({temp.s , nx , ny , temp.d + 1}) ;
                        }
                    } else if (grid[nx][ny] >= 'a' && grid[nx][ny] <= 'z') {
                        int ns = temp.s | (1 << p[grid[nx][ny] - 'a']) ;
                        if (!vis[ns][nx][ny]) {
                            vis[ns][nx][ny] = true ;
                            q.push({ns, nx , ny , temp.d + 1}) ;
                        }
                    } else if (grid[nx][ny] >= 'A' && grid[nx][ny] <= 'Z') {
                        int ns = temp.s ;
                        if ((ns >> (p[grid[nx][ny] - 'A'])) & 1) {
                            if (!vis[ns][nx][ny]) {
                                vis[ns][nx][ny] = true ;
                                q.push({ns, nx , ny , temp.d + 1}) ;
                            }
                        }
                    }
                }
            }
        }

        return -1 ;

        
    }
};