class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size() ;
        vector<int> res(n , 0) ;
        stack<int> st ;
        for (int i = 0 ; i < n ; ++i) {
            while (!st.empty()) {
                int u = st.top() ;
                if (T[u] < T[i]) {
                    res[u] = i - u ;
                    st.pop() ;
                } else {
                    break ;
                }
            }
            st.push(i) ;
        }
        while (!st.empty()) {
            res[st.top()] = 0 ;
            st.pop() ;
        }
        return res ;
    }
};