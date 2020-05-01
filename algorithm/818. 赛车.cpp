class Solution {
public:
    int racecar(int target) {
        target = abs(target) ;
        vector<unordered_map<int,int>> dp(target * 4 + 1) ;

        queue<pair<int,int>> q ;
        dp[0][1] = 0 ;
        q.push({0 , 1}) ;

        while (!q.empty()) {
            auto pr = q.front() ; q.pop() ;
            if (pr.first == target) {
                return dp[pr.first][pr.second] ;
            }
            //A 
            int fi = pr.first + pr.second , se = pr.second * 2 ;
            if (fi >= 0 && fi <= target * 4) {
                if (dp[fi].find(se) == dp[fi].end()) {
                    dp[fi][se] = dp[pr.first][pr.second] + 1 ;
                    q.push({fi , se}) ;
                }
            }
            fi = pr.first ;
            if (pr.second > 0)
                se = -1 ;
            else se = 1 ;
            if (dp[fi].find(se) == dp[fi].end()) {
                dp[fi][se] = dp[pr.first][pr.second] + 1 ;
                q.push({fi , se}) ;
            }
        }
        return 0 ;
    }
};