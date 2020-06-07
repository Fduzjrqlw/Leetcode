class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size() , res = 0 ;
        map<pair<int,int> , int> mp1 , mp2 ;
        for (int i = 0 ; i < n ; ++i) {
            for (int j = 0 ; j < n ; ++j) {
                if (grid[i][j] > 0) {
                    ++res ;
                    for (int k = 0 ; k < grid[i][j] ; ++k) {
                        mp1[{i , k}]++ ;
                        mp2[{j , k}]++ ;
                    }
                }
            }
        }
        res += mp1.size() + mp2.size() ;
        return res ;
    }
};