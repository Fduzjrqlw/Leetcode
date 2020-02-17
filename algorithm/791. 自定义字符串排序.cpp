class Solution {
public:
    string customSortString(string S, string T) {
        unordered_map<char,int> word2int ;
        unordered_map<int,char> int2word ;
        int dictSize = S.length() ;
        for (int i = 0 ; i < S.length() ; ++i) {
            word2int[S[i]] = i ;
            int2word[i] = S[i] ;
        }
        for (char c = 'a' ; c <= 'z' ; ++c) {
            if (word2int.find(c) == word2int.end()) {
                word2int[c] = dictSize ;
                int2word[dictSize] = c ;
                ++dictSize ;
            }
        }
        vector<int> temp ;
        for (int i = 0 ; i < T.length() ; ++i) {
            temp.push_back(word2int[T[i]]) ;
        }
        sort(temp.begin() , temp.end()) ;
        string res = "" ;
        for (int i = 0 ; i < temp.size() ; ++i) {
            res += int2word[temp[i]] ;
        }
        return res ;
    }
};