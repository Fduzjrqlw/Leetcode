
class Solution {
public:

    struct node {
        char c ;
        int num ;
        friend bool operator <(const node &A , const node &B) {
            return A.num < B.num ;
        }
    } ;

    string reorganizeString(string S) {
        int n = S.length() ;
        unordered_map<char,int> count ;
        for (int i = 0 ; i < n ; ++i) {
            count[S[i]]++ ;
        }
        priority_queue<node> pq ;
        for (auto v : count) {
            node temp ;
            temp.c = v.first ;
            temp.num = v.second ;
            pq.push(temp) ;
        }
        string res = "" ;
        char last = 'A' ;
        while (!pq.empty()) {
            node fir = pq.top() ; pq.pop() ;
            if (fir.c != last) {
                fir.num-- ;
                last = fir.c ;
                res += fir.c ;
                if (fir.num != 0) {
                    pq.push(fir) ;
                }
            } else {
                if (pq.empty()) {
                    return "" ;
                }
                node sec = pq.top() ; pq.pop() ;
                pq.push(fir) ;
                last = sec.c ;
                sec.num-- ;
                res += sec.c ;
                if (sec.num != 0) {
                    pq.push(sec) ;
                }
            }
        }
        return res ;
    }
};