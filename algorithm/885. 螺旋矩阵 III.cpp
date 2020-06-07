class Solution {
public:

    const int dx[4] = {0 , 1 , 0 , -1} ;
    const int dy[4] = {1 , 0 , -1 , 0} ;

    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        vector<vector<bool>> vis(R , vector<bool> (C , false)) ;

        vector<vector<int>> res ;

        int d = 1 , cnt = R * C , dir = 0 ;

        while (cnt > 0) {
            for (int i = 0 ; i <= d ; ++i) {
                if (r0 + i * dx[dir] >= 0 && r0 + i * dx[dir] < R && c0 + i * dy[dir] >= 0 && c0 + i * dy[dir] < C) {
                    if (!vis[r0 + i * dx[dir]][c0 + i * dy[dir]]) {
                        vis[r0 + i * dx[dir]][c0 + i * dy[dir]] = true ;
                        --cnt ;
                        res.push_back({r0 + i * dx[dir] , c0 + i * dy[dir]}) ;
                    }
                }
            }
            r0 = r0 + d * dx[dir] ;
            c0 = c0 + d * dy[dir] ;
            dir = (dir + 1) % 4 ;
            if (dir == 0 || dir == 2) {
                ++d ;
            }
        }
        return res ;
    }
};