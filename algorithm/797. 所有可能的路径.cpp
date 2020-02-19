class Solution {
public:

    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        map<vector<int>,int> mp ;
        vector<vector<int>> res ;
        mp[{0}] = 1 ;
        int n = graph.size() ;

        queue<pair<int,vector<int>>> q ;
        q.push({0 , {0}}) ;

        while (!q.empty()) {
            auto state = q.front() ; q.pop() ;
            if (state.first == n - 1) {
                res.push_back(state.second) ;
                continue ;
            }
            for (int i = 0 ; i < graph[state.first].size() ; ++i) {
                int v = graph[state.first][i] ;
                state.second.push_back(v) ;
                if (mp.find(state.second) == mp.end()) {
                    mp[state.second] = 1 ;
                    q.push({v , state.second}) ;
                }
                state.second.pop_back() ;
            }
        }
        return res ;

    }
};