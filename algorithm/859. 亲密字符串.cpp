class Solution {
public:
    bool buddyStrings(string A, string B) {
        int n = A.length() ;
        if (n != B.length())
            return false ;
        vector<int> res ;
        for (int i = 0 ; i < n ; ++i) {
            if (A[i] != B[i]) {
                res.push_back(i) ;
                if (res.size() > 2) {
                    return false ;
                }
            }
        }
        if (res.size() == 1)
            return false ;
        //cout << res[0] << " " << res[1] << endl ;
        bool flag = false ;
        if (res.size() == 2)
            if ((A[res[0]] == B[res[1]]) && (A[res[1]] == B[res[0]]))
                flag = true ;
            else return false ;
        unordered_map<char,int> mp ;
        for (int i = 0 ; i < n ; ++i) {
            mp[A[i]]++ ;
            if (mp[A[i]] >= 2) {
                flag = true ;
                break ;
            }
        }
        return flag ;
    }
};