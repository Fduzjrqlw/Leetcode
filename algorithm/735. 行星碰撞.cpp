class Solution {
public:
    struct node {
        int pos , m ;
        friend bool operator <(const node &A , const node &B) {
            return A.m < B.m ;
        }
    } ;

    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size() ;
        vector<int> res ;
        stack<int> st ;
        for (int i = 0 ; i < n ; ++i) {
            bool save = true ;
            while (!st.empty()) {
                int u = st.top() ;
                if (asteroids[u] < 0) {
                    break ;
                }
                if (asteroids[i] > 0) {
                    break ;
                }
                if (asteroids[i] + asteroids[u] == 0) {
                    save = false ;
                    st.pop() ;
                    break ;
                }
                if (abs(asteroids[i]) > abs(asteroids[u])) {
                    st.pop() ;
                } else {
                    save = false ;
                    break ;
                }
            }
            if (save) {
                st.push(i) ;
            }
        }
        while (!st.empty()) {
            res.push_back(asteroids[st.top()]) ; st.pop() ;
        }
        if (res.size() != 0) {
            reverse(res.begin() , res.end()) ;
        }
        return res ;
    }
};