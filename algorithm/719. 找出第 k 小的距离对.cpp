class Solution {
public:

    int count(int target , vector<int>& nums) {
        int n = nums.size() ;
        int tot = 0 , j = 1;
        for (int i = 0 ; i < n ; ++i) {
            while (j < n && nums[j] - nums[i] <= target) {
                ++j ;
            }
            tot += (j - i - 1) ;
        }
        return tot ;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size() ;
        sort(nums.begin() , nums.end()) ;
        int minimal = nums[0] , maximal = nums[n - 1] ;
        int l = 0 , r = maximal - minimal ;
        while (l < r) {
            int mid = (l + r) >> 1 ;
            int tot = count(mid , nums) ;
            if (tot >= k) {
                r = mid ;
            } else {
                l = mid + 1 ;
            }
        }
        return l ;
    }
};