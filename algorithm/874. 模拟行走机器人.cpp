class Solution {
public:


    const int dx[4] = {0 , 1 , 0 , -1} ;
    const int dy[4] = {1 , 0 , -1 , 0} ;

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        map<pair<int,int> , bool> obs ;
        int res = 0 ;
        for (int i = 0 ; i < obstacles.size() ; ++i) {
            obs[{obstacles[i][0] , obstacles[i][1]}] = true ;
        }
        int x = 0 , y = 0 , dir = 0 ;
        for (int i = 0 ; i < commands.size() ; ++i) {
            if (commands[i] > 0) {
                for (int j = 1 ; j <= commands[i] ; ++j) {
                    if (obs.find({x + dx[dir] , y + dy[dir]}) != obs.end()) {
                        break ;
                    }
                    x += dx[dir] ; y += dy[dir] ;
                    res = max(res , x * x + y * y) ;
                }
            } else if (commands[i] == -2) {
                dir = (dir - 1 + 4) % 4 ;
            } else if (commands[i] == -1) {
                dir = (dir + 1) % 4 ;
            }
        }
        return res ;
    }
};