class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int L = S.length() , res = 0 ;
        vector<map<int , int>> mp (26);
        for (int i = 0 ; i < L ; ++i) {
            mp[S[i] - 'a'][i] = 1 ;
        }
        for (int i = 0 ; i < words.size() ; ++i) {
            int pos = 0 ;
            for (int j = 0 ; j < words[i].length() ; ++j) {
                auto it = mp[words[i][j] - 'a'].lower_bound(pos) ;
                if (it == mp[words[i][j] - 'a'].end()) {
                    --res ;
                    break ;
                }
                pos = it->first + 1 ;
            }
            ++res ;
        }
        return res ;
    
    }
};