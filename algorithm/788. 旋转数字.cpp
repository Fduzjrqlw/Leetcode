class Solution {
public:

    bool check(int x , unordered_map<char,char> &mp) {
        string s = to_string(x) , t = "" ;
        for (int i = 0 ; i < s.length() ; ++i) {
            if (mp.find(s[i]) == mp.end()) {
                return false ;
            }
            t += mp[s[i]] ;
        }
        return (s != t) ;
    }

    int rotatedDigits(int N) {
        int res = 0 ;
        unordered_map<char,char> mp ;
        mp['1'] = '1' ; mp['0'] = '0' ; mp['8'] = '8' ; 
        mp['2'] = '5' ; mp['5'] = '2' ; mp['6'] = '9' ; mp['9'] = '6' ;
        for (int i = 1 ; i <= N ; ++i) {
            if (check(i , mp)) {
                //cout << i << endl ;
                ++res ;
            }
        }
        return res ;
    }
};