class Solution {
public:

    const int maxnum = 10000 ;
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size() , res = 0 ;
        unordered_map<int,int> count ;
        vector<vector<int>> dp(maxnum + 1 , vector<int> (2,  0)) ;
        for (int i = 0 ; i < n ; ++i) {
            count[nums[i]]++ ;
        }
        dp[0][0] = 0 ; dp[0][1] = 0 ;
        //0未删除   //1删除
        for (int i = 1 ; i <= maxnum ; ++i) {
            dp[i][0] = max(dp[i - 1][0] , dp[i - 1][1]) ;
            dp[i][1] = dp[i - 1][0] + count[i] * i ;
        }
        res = max(dp[maxnum][0] , dp[maxnum][1]) ;
        return res ;
    }
};