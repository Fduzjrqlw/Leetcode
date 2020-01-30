class Solution {
public:

    bool res ;

    void dfs(int pos , vector<int>& nums , int k , vector<int>& temp_sum , int& target) {
        if (res) {
            return ;
        }
        if (pos == nums.size()) {
            for (int i = 0 ; i < k ; ++i) {
                if (temp_sum[i] != target) {
                    return ;
                }
            }
            res = true ;
            return ;
        }

        for (int i = 0 ; i < k ; ++i) {
            if (nums[pos] + temp_sum[i] <= target) {
                temp_sum[i] += nums[pos] ;
                dfs(pos + 1 , nums , k , temp_sum , target) ;
                temp_sum[i] -= nums[pos] ;
            }
        }
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0 ;
        for (int i = 0 ; i < nums.size() ; ++i) {
            sum += nums[i] ;
        }
        if (k == 1) {
            return true ;
        }
        if (sum % k != 0) {
            return false ;
        }
        sort(nums.begin() , nums.end()) ;
        reverse(nums.begin() , nums.end()) ;
        vector<int> temp_sum(k , 0) ;
        res = false ;
        int target = sum / k ;
        dfs(0 , nums , k , temp_sum , target) ;
        return res ;
    }
};