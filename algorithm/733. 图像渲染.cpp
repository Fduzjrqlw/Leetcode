class Solution {
public:

    const int dx[4] = {0 , 1 , 0 , -1} ;
    const int dy[4] = {1 , 0 , -1 , 0} ;

    void dfs(vector<vector<int>>& image, vector<vector<bool>>& vis , int sr, int sc, int newColor , int rawColor) {
        image[sr][sc] = newColor ;
        vis[sr][sc] = true ;
        for (int d = 0 ; d < 4 ; ++d) {
            if (sr + dx[d] >= 0 && sr + dx[d] < image.size() && sc + dy[d] >= 0 && sc + dy[d] < image[0].size()) {
                if (!vis[sr + dx[d]][sc + dy[d]] && image[sr + dx[d]][sc + dy[d]] == rawColor) {
                    dfs(image , vis , sr + dx[d] , sc + dy[d] , newColor , rawColor) ;
                }
            }
        }
        return ;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size() , n = image[0].size() ;
        int rawColor = image[sr][sc] ;
        vector<vector<bool>> vis(m , vector<bool>(n , false)) ;
        dfs(image , vis , sr , sc , newColor , rawColor) ;
        return image ;
    }
};