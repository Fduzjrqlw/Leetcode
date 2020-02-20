class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        vector<int> res(2 , 0) ;
        res[0] = 1 ;
        int sum = 0 ;
        for (int i = 0 ; i < S.length() ; ++i) {
            if (sum + widths[S[i] - 'a'] > 100) {
                sum = widths[S[i] - 'a'] ;
                ++res[0] ;
                res[1] = sum ;
            } else {
                sum += widths[S[i] - 'a'] ;
                res[1] = sum ;
            }
        }
        return res ;
    }
};