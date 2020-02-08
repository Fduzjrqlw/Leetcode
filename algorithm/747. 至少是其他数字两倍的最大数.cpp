class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int pos = 0 ;
        for (int i = 1 ; i < nums.size() ; ++i) {
            if (nums[i] > nums[pos]) {
                pos = i ;
            }
        }
        for (int i = 0 ; i < nums.size() ; ++i) {
            if (i != pos) {
                if (nums[i] * 2 > nums[pos]) {
                    return-1 ;
                }
            }
        }
        return pos ;
    }
};