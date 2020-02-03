class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0 ;
        int n = nums.size() ;
        for (int i = 0 ; i < n ; ++i) {
            sum += nums[i] ;
        }
        int t = 0 ;
        for (int i = 0 ; i < n ; ++i) {
            t += nums[i] ;
            if (sum - t == t - nums[i]) {
                return i ;
            }
        }
        return -1 ;
    }
};