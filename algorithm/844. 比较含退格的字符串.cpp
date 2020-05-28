class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s , t ;
        for (int i = 0 ; i < S.length() ; ++i) {
            if (S[i] == '#') {
                if (!s.empty()) {
                    s.pop() ;
                }
            } else s.push(S[i]) ;
        }
        for (int i = 0 ; i < T.length() ; ++i) {
            if (T[i] == '#') {
                if (!t.empty()) {
                    t.pop() ;
                }
            } else t.push(T[i]) ;
        }
        if (s.size() != t.size()) {
            return false ;
        }
        while (!s.empty()) {
            if (s.top() != t.top())
                return false ;
            s.pop() ;
            t.pop() ;
        }
        return true ;
    }
};