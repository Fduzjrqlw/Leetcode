class Solution {
public:
    bool rotateString(string A, string B) {
        if (A.length() != B.length())
            return false ;
        if (A.length() == 0) {
            return true ;
        }
        string C = A + A ;
        for (int i = 0 ; i < A.length() ; ++i) {
            if (C.substr(i , A.length()) == B)
                return true ;
        }
        return false ;
    }
};