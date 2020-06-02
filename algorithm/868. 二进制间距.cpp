class Solution {
public:
    int binaryGap(int N) {
        vector<int> s ;
        while (N) {
            s.push_back(N & 1) ;
            N >>= 1 ;
        }
        int res = 0 ;
        int p = -1 ;
        for (int i = 0 ; i < s.size() ; ++i) {
            if (s[i] == 1) {
                if (p == -1) {
                    p = i ;
                } else {
                    res = max(res , i - p) ;
                    p = i ;
                }
            }
        }
        return res ;
    }
};