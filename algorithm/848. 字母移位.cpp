class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        int n = S.length() ;
        int d = 0 ;
        string t = S ;

        for (int i = n - 1 ; i >= 0 ; --i) {
            d += shifts[i] ;
            d %= 26 ;
            t[i] = ('a' + ((S[i] - 'a' + d) % 26)) ;
        }
        return t ;
    }
};