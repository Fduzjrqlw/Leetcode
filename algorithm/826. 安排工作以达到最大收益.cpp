class Solution {
public:

    struct Job {
        int d , p , id ;
    } ;


    static bool cmp_jobs(const Job &a , const Job &b) {
        return a.d < b.d ;
    }

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = profit.size() , m = worker.size() , res = 0 ;
        vector<Job> jobs(n) ;
        for (int i = 0 ; i < n ; ++i) {
            jobs[i].d = difficulty[i] ;
            jobs[i].p = profit[i] ;
            jobs[i].id = i ;
        }
        sort(jobs.begin() , jobs.end() , cmp_jobs) ;
        sort(worker.begin() , worker.end()) ;

        int ind = 0 , t = 0 ;

        for (int i = 0 ; i < m ; ++i) {
            while (ind < n && jobs[ind].d <= worker[i]) {
                t = max(t , jobs[ind].p) ;
                ++ind ;
            }
            res += t ;
        }

        return res ;

    }
};