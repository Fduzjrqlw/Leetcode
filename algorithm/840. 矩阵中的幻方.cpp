class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int res = 0 ;
        
        int m = grid.size() , n = grid[0].size() ;
        for (int i = 0 ; i + 3 <= m ; ++i) {
            for (int j = 0 ; j + 3 <= n ; ++j) {
                unordered_map<int,int> mp ;
                unordered_map<int,int> np ;
                for (int l = 0 ; l < 3 ; ++l) {
                    int t = 0 ;
                    for (int k = 0 ; k < 3 ; ++k) {
                        t += grid[i + l][j + k] ;
                        np[grid[i + l][j + k]]++ ;
                    }
                    mp[t]++ ;
                }
                for (int l = 0 ; l < 3 ; ++l) {
                    int t = 0 ;
                    for (int k = 0 ; k < 3 ; ++k) {
                        t += grid[i + k][j + l] ;
                    }
                    mp[t]++ ;
                }
                int t = 0 ;
                for (int l = 0 ; l < 3 ; ++l) {
                    t += grid[i + l][j + l] ;
                }
                mp[t]++ ;
                t = 0 ;
                for (int l = 0 ; l < 3 ; ++l) {
                    t += grid[i + l][j + 2 - l] ;
                }
                mp[t]++ ;
                if (mp.size() == 1) {
                    bool flag = true ;
                    for (int l = 1 ; l <= 9 ; ++l) {
                        if (np[l] != 1) {
                            flag = false ;
                            break ;
                        }
                    }
                    if (flag)
                        ++res ;
                }
            }
        }
        return res ;
    }
};