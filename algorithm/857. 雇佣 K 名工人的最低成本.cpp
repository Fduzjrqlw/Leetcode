class Solution {
public:


    struct workers {
        int q , w ;
        double per ;
    } ;

    static bool cmp(const workers&A , const workers &B) {
        if (A.per != B.per)
            return A.per < B.per ;
        return A.w < B.w ;
    }

    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        int n = quality.size() ;
        double res = 1e12, s = 0.00 ;
        vector<workers> wks ;
        for (int i = 0 ; i < n ; ++i) {
            wks.push_back({quality[i] , wage[i] , wage[i] * 1.0 / (1.0 * quality[i])}) ;
        }
        sort(wks.begin() , wks.end() , cmp) ;

        priority_queue<double> pq ;

        for (int i = 0 ; i < K - 1 ; ++i) {
            s += 1.00 * wks[i].q  ;
            pq.push(wks[i].q) ;
        }

        for (int i = K - 1 ; i < n ; ++i) {
            double t = wks[i].q  ;
            res = min(res , (t + s) / (wks[i].q * 1.00) * wks[i].w) ;
            if (K > 1) {
                if (pq.top() > 1.00 * wks[i].q) {
                    s -= pq.top() ;
                    pq.pop() ;
                    s += 1.00 * wks[i].q ;
                    pq.push(wks[i].q) ;
                }
            }
        }

        return res ;
        
        
    }
};