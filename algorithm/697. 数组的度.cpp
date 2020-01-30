class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> L , R , count ;
        if (nums.size() == 0)
            return 0 ;
        for (int i = 0 ; i < nums.size() ; ++i) {
            count[nums[i]]++ ;
            if (L.find(nums[i]) == L.end()) {
                L[nums[i]] = i ;
            }
            R[nums[i]] = i ;
        }
        int maxl = 0 , res = 0 ;
        for (auto v : count) {
            if (v.second > maxl) {
                maxl = v.second ;
                res = R[v.first] - L[v.first] + 1 ;
            } else if (v.second == maxl) {
                res = min(res , R[v.first] - L[v.first] + 1) ;
            }
        }
        return res ;
    }
};