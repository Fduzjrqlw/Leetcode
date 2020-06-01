class Solution {
public:

    struct node {
        int p , val ;
    } ;

    int shortestSubarray(vector<int>& A, int K) {
        int n = A.size() , res = INT_MAX ;
        vector<node> sum ;
        sum.push_back({0 , 0}) ;
        int s = 0 ;
        for (int i = 0 ; i < n ; ++i) {
            s += A[i] ;
            sum.push_back({i + 1 , s}) ;
        }

        deque<node> dq ;
        dq.push_front(sum[0]) ;

        for (int i = 1 ; i <= n ; ++i) {
            while(!dq.empty()) {
                if (dq.front().val + K <= sum[i].val) {
                    res = min(res , sum[i].p - dq.front().p) ;
                    dq.pop_front() ;
                } else break ;
            }
            while (!dq.empty()) {
                if (dq.back().val >= sum[i].val) {
                    dq.pop_back() ;
                } else break ;
            }
            dq.push_back(sum[i]) ;
        }
        if (res == INT_MAX)
            return -1 ;
        return res ;
        
    }
};