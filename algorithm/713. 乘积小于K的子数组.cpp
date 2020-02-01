class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size() , res = 0 ;
        vector<int> R(n + 1, 0) ;
        R[n - 1] = n ; // R[i]表示在i右侧第一个不为1的位置
        nums.push_back(1) ;
        for (int i = n - 2 ; i >= 0 ; --i) {
            if (i == n - 2 || nums[i + 1] != 1) {
                R[i] = i + 1 ;
            } else R[i] = R[i + 1] ;
        }
        for (int i = 0 ; i < n ; ++i) {
            int t = nums[i] , pos = i , last_pos = i - 1;
            while (t < k) {
                res += (pos - last_pos) ;
                last_pos = pos ;
                if (R[pos] != pos + 1) {
                    res += R[pos] - pos - 1;
                    last_pos = R[pos] - 1 ;
                }
                pos = R[pos] ;
                if (pos >= n) {
                    break ;
                }
                t = t * nums[pos] ;
            }
        }
        return res ;
    }
};