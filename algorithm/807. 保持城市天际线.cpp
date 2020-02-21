class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size() , res = 0 ;
        vector<int> row(m , 0) ;
        vector<int> col(n , 0) ;
        for (int i = 0 ; i < m ; ++i) {
            for (int j = 0 ; j < n ; ++j) {
                row[i] = max(row[i] , grid[i][j]) ;
                col[j] = max(col[j] , grid[i][j]) ;
            }
        }
        for (int i = 0 ; i < m ; ++i) {
            for (int j = 0 ; j < n ; ++j) {
                res += max(0 , min(col[j] , row[i]) - grid[i][j]) ;
            }
        }
        return res ;
    }
};