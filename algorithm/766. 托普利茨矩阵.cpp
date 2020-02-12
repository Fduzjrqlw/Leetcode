class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int x = 0 , y = 0 , m = matrix.size() , n = matrix[0].size() ;
        for (int i = 0 ; i < n ; ++i) {
            x = 0 , y = i ;
            while (x < m && y < n) {
                if (matrix[x][y] != matrix[0][i]) {
                    return false ;
                }
                ++x ; ++y ;
            }
        }
        for (int i = 0 ; i < m ; ++i) {
            x = i , y = 0 ;
            while (x < m && y < n) {
                if (matrix[x][y] != matrix[i][0]) {
                    return false ;
                }
                ++x ; ++y ;
            }
        }
        return true ;
    }
    
};