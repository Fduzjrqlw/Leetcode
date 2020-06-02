class Solution {
public:
    bool reorderedPowerOf2(int N) {
        unordered_map<int,int> mpn ;
        string s = to_string(N) ;
        for (int i = 0 ; i < s.length() ; ++i) {
            mpn[s[i] - '0']++ ;
        }
        for (long long x = 1 ; x <= INT_MAX ; x <<= 1) {
            unordered_map<int,int> temp ;
            string t = to_string(x) ;
            for (int j = 0 ; j < t.length() ; ++j) {
                temp[t[j] - '0']++ ;
            }
            bool flag = true ;
            for (auto v : mpn) {
                if (v.second != temp[v.first]) {
                    flag = false ;
                    break ;
                }
            }
            for (auto v : temp) {
                if (v.second != mpn[v.first]) {
                    flag = false ;
                    break ;
                }
            }
            if (flag) {
                return true ;
            }
        }
        return false ;
    }
};