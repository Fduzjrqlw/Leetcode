class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> res ;
        int p = 0 ;
        while (p < S.length()) {
            int q = p ;
            while (q < S.length() && S[p] == S[q]) {
                ++q ;
            }
            if (q - p >= 3) {
                res.push_back({p , q - 1}) ;
            }
            p = q ;
        }
        return res ;
    }
};