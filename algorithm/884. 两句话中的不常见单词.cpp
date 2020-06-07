class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        vector<string> res ;
        unordered_map<string,int> hash ;
        string temp = "" ;
        for (int i = 0 ; i < A.length() ; ++i) {
            if (A[i] != ' ') {
                temp += A[i] ;
            }
            if (i + 1 == A.length() || A[i] == ' ') {
                hash[temp]++ ;
                temp = "" ;
            }
        }
        for (int i = 0 ; i < B.length() ; ++i) {
            if (B[i] != ' ') {
                temp += B[i] ;
            }
            if (i + 1 == B.length() || B[i] == ' ') {
                hash[temp]++ ;
                temp = "" ;
            }
        }
        for (auto v : hash) {
            if (v.second == 1) {
                res.push_back(v.first) ;
            }
        }
        return res ;
    }
};