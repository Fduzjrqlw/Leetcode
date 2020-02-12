class Solution {
public:

    unordered_map<char,int> right ;
    unordered_map<char,int> use ;
    vector<int> partitionLabels(string S) {
        int res = 0 ;
        for (int i = 0 ; i < S.length() ; ++i) {
            right[S[i]] = i ;
        }
        vector<int> len ;
        int l = 0 ;
        for (int i = 0 ; i < S.length() ; ++i) {
            if (use.size() == 0) {
                ++res ;
            }
            ++l ;
            use[S[i]] = 1 ;
            if (right[S[i]] == i) {
                use.erase(use.find(S[i])) ;
            }
            if (use.size() == 0 || i + 1 == S.length()) {
                len.push_back(l) ;
                l = 0 ;
            }
        }
        return len ;

    }
};