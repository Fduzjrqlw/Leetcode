class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return -1 ;
        int l = 0 , r = nums.size() - 1 ;
        //找最小的l,使得nums[l] >= target
        while (l < r) {
            int mid = (l + r + 1) >> 1 ;
            if (nums[mid] > target) {
                r = mid - 1 ;
            } else {
                l = mid ;
            }
        }
        if (nums[l] == target) {
            return l ;
        }
        return -1 ;
    }
};