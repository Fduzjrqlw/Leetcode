class Solution {
public:

    struct Node {
        map<string,int> atom ;
        int state ;
        //state = 0 普通方程式
        //state = 1 左括号
    } ;

    string countOfAtoms(string formula) {
        map<string,int> res ;
        stack<Node> st ;
        for (int i = 0 ; i < formula.length() ;) {
            if (formula[i] == '(') {
                Node nt ;
                nt.state = 1 ;
                st.push(nt) ;
                ++i ;
            } else if (formula[i] == ')') {
                ++i ;
                int t = 1 ;
                if (i < formula.length() && formula[i] >= '0' && formula[i] <= '9') {
                    t = 0 ;
                    while (i < formula.length() && formula[i] >= '0' && formula[i] <= '9') {
                        t = t * 10 + (formula[i ++] -'0') ;
                    }
                }
                map<string,int> tempAtom ;
                while (!st.empty()) {
                    Node nt = st.top() ; st.pop() ;
                    if (nt.state == 1) {
                        break ;
                    }
                    for (auto v : nt.atom) {
                        tempAtom[v.first] += v.second ;
                    }
                }
                for (auto &v : tempAtom) {
                    v.second *= t ;
                }
                Node nt ;
                nt.atom = tempAtom ; 
                nt.state = 0 ;
                st.push(nt) ;
            } else {
                string temp = "" ;
                temp += formula[i++] ;
                int t = 1 ;
                while (i < formula.length() && formula[i] >= 'a' && formula[i] <= 'z') {
                    temp += formula[i++] ;
                }
                if (i < formula.length() && formula[i] >= '0' && formula[i] <= '9') {
                    t = 0 ;
                    while (i < formula.length() && formula[i] >= '0' && formula[i] <= '9') {
                        t = t * 10 + (formula[i++] - '0') ;
                    }
                }
                Node nt ;
                nt.state = 0 ;
                nt.atom[temp] = t ;
                st.push(nt) ;
            }
        }
        while (!st.empty()) {
            Node nt = st.top() ; st.pop() ;
            for (auto v : nt.atom) {
                res[v.first] += v.second ;
            }
        }
        string ans = "" ;
        for (auto v : res) {
            ans += v.first ;
            if (v.second > 1) {
                ans += to_string(v.second) ;
            }
        }
        return ans ;
    }
};