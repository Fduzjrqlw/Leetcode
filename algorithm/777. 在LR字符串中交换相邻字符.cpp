class Solution {
public:
    bool canTransform(string start, string end) {
        if (start.length() != end.length()) {
            return false ;
        }
        int n = start.length() ;
        string raw1 = "" , raw2 = "" ;
        for (int i = 0 ; i < n ; ++i) {
            if (start[i] != 'X') {
                raw1 += start[i] ;
            }
        }
        for (int i = 0 ; i < n ; ++i) {
            if (end[i] != 'X') {
                raw2 += end[i] ;
            }
        }
        if (raw1 != raw2) {
            return false ;
        }
        int pos = 0 ;
        for (int i = 0 ; i < n ; ++i) {
            if (start[i] == 'L') {
                while (pos < n && end[pos] != 'L') {
                    ++pos ;
                }
                if (i < pos) {
                    return false ;
                }
                ++pos ;
            }
        }
        pos = 0 ;
        for (int i = 0 ; i < n ; ++i) {
            if (start[i] == 'R') {
                while (pos < n && end[pos] != 'R') {
                    ++pos ;
                }
                if (i > pos) {
                    return false ;
                }
                ++pos ;
            }
        }
        return true ;
    }
};