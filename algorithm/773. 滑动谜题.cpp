class Solution {
public:

    struct State {
        string s ;
        int step , x0 , y0 ;
    } ;
    int dx[4] = {0 , 1 , 0 , -1} ;
    int dy[4] = {-1 , 0 , 1 , 0} ;
    int slidingPuzzle(vector<vector<int>>& board) {
        queue<State> q ;
        State start ;
        unordered_map<string,int> mp ;
        string End = "123450" ;
        for (int i = 0 ; i < 2 ; ++i) {
            for (int j = 0 ; j < 3 ; ++j) {
                start.s += ('0' + board[i][j]) ;
                if (board[i][j] == 0) {
                    start.x0 = i ; start.y0 = j ;
                }
            }
        }
        mp[start.s] = 1 ;
        start.step = 0 ;
        q.push(start) ; 
        while (!q.empty()) {
            start = q.front() ; q.pop() ;
            if (start.s == End) {
                return start.step ;
            }
            State nextState ;
            nextState.step = start.step + 1 ;
            for (int k = 0 ; k < 4 ; ++k) {
                if (start.x0 + dx[k] >= 0 && start.x0 + dx[k] < 2 && start.y0 + dy[k] >= 0 && start.y0 + dy[k] < 3) {
                    nextState.s = start.s ;
                    nextState.x0 = start.x0 + dx[k] ;
                    nextState.y0 = start.y0 + dy[k] ;
                    int pos0 = (start.x0 * 3 + start.y0) ;
                    int pos1 = (nextState.x0 * 3 + nextState.y0) ;
                    swap(nextState.s[pos0] , nextState.s[pos1]) ;
                    if (mp.find(nextState.s) == mp.end()) {
                        mp[nextState.s] = 1 ;
                        q.push(nextState) ;
                    }
                }
            }
        }
        return -1 ;
    }
};