class ExamRoom {
public:


    unordered_map<int,int> vis ;
    unordered_map<int,int> lp , rp ;
    struct node {
        int l , r , len ;
        friend bool operator < (const node &A , const node &B) {
            if ((A.len + 1) / 2 != (B.len + 1) / 2) {
                return ((A.len + 1)) / 2 < ((B.len + 1) / 2) ;
            } else return A.l > B.l ;
        }
    } ;

    int n , m , L , R ;
    priority_queue<node> pq ;
    ExamRoom(int N) {
        n = N ;
        m = 0 ;
    }
    
    int seat() {
        int res = 0 ;
        if (m != 0) {
            int c1 = L - 0 ;
            int c2 = (n - 1 - R) ;
            int c3 = -0x7f7f ;
            node tp ;
            while (!pq.empty()) {
                tp = pq.top() ;
                int mid = (tp.l + tp.r) / 2 ;
                if (vis[tp.l] == 0 || vis[tp.r] == 0 || tp.len <= 0 || vis[mid] == 1) {
                    pq.pop() ;
                } else break ;
            }
            if (!pq.empty()) {
                tp = pq.top() ;
                c3 = (tp.len + 1) / 2 ;
            }
            //c1作为答案
            if (c1 >= c2 && c1 >= c3) {
                pq.push({0 , L , L - 1}) ;
                lp[L] = 0 ;
                lp[0] = -1 ;
                rp[0] = L ;
                L = 0 ;
                res = 0 ;
            } else if (c3 >= c1 && c3 >= c2) {
                int mid = (tp.l + tp.r) / 2 ;
                pq.pop() ;
                pq.push({tp.l , mid , mid - tp.l - 1}) ;
                pq.push({mid , tp.r , tp.r - mid - 1}) ;
                lp[mid] = tp.l ;
                rp[tp.l] = mid ;
                rp[mid] = tp.r ;
                lp[tp.r] = mid ;
                res = mid ;         
            } else {
                pq.push({R , n - 1 , n - 1 - R - 1}) ;
                rp[R] = n - 1 ;
                lp[n - 1] = R ;
                rp[n - 1] = -1 ;
                R = n - 1 ;
                res = n - 1 ;
            }
        } else {
            L = 0 ; R = 0 ;
            res = 0 ;
            lp[0] = -1 ; rp[0] = -1 ;
        } 
        ++m ;
        vis[res] = 1 ;
        return res ;
    }
    
    void leave(int p) {
        if (m == 1) {
            L = 0 ; R = 0 ;
            while (!pq.empty())
                pq.pop() ;
        } else {
            if (lp[p] == -1) {
                L = rp[p] ;
                lp[rp[p]] = -1 ;
            } else if (rp[p] == -1) {
                R = lp[p] ;
                rp[lp[p]] = -1 ;
            } else {
                pq.push({lp[p] , rp[p] , rp[p] - lp[p] - 1}) ;
            }
        }
        --m ;
        vis[p] = 0 ;
        lp[p] = rp[p] = -1 ;
        return ;

    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */