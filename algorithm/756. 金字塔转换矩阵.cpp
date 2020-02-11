class Solution {
public:

    vector<char> G[7][7] ;
    unordered_map<string,bool> memo ;

    void generate(int pos , string &bottom , vector<string>& state , string &t) {
        if (pos == bottom.length() - 1) {
            state.push_back(t) ;
            return ;
        }
        for (int i = 0 ; i < G[bottom[pos] - 'A'][bottom[pos + 1] - 'A'].size() ; ++i) {
            t[pos] = G[bottom[pos] - 'A'][bottom[pos + 1] - 'A'][i] ;
            generate(pos + 1 , bottom , state , t) ;
        }
    }
    
    bool dfs(string bottom) {
        if (memo.find(bottom) != memo.end()) {
            return memo[bottom] ;
        }
        if (bottom.size() == 1) {
            memo[bottom] = true ;
            return true ;
        }
        vector<string> state ;
        string temp = bottom.substr(1) ;
        generate(0 , bottom , state , temp) ;
        for (int i = 0 ; i < state.size() ; ++i) {
            if (dfs(state[i])) {
                memo[bottom] = true ;
                return true ;
            }
        }
        memo[bottom] = false ;
        return false ;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        int l = bottom.length() ;
        for (int i = 0 ; i < allowed.size() ; ++i) {
            G[allowed[i][0] - 'A'][allowed[i][1] - 'A'].push_back(allowed[i][2]) ;
        }
        return dfs(bottom) ;
    }
};