class Solution {
public:
    int n , m ;
    vector<int> blackList ;
    unordered_map<int,int> hash ;
    Solution(int N, vector<int>& blacklist) {
        n = N ;
        blackList = blacklist ;
        m = blacklist.size() ;
        for (int i = 0 ; i < m ; ++i) {
            hash[blacklist[i]]++ ;
        }
        if (m > 0) {
            sort(blackList.begin() , blackList.end()) ;
        }
        int lst = n - 1 ;
        for (int i = 0 ; i < m ; ++i) {
            if (blackList[i] >= n - m) {
                break ;
            }
            while (hash.find(lst) != hash.end()) {
                --lst ;
            }
            hash[blackList[i]] = lst ;
            --lst ;
        }
    }
    
    int pick() {
        if (blackList.size() == 0) {
            return (rand() % n) ;
        }
        int x = rand() % (n - m) ;
        if (hash.find(x) == hash.end()) {
            return x ;
        }
        return hash[x] ;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */