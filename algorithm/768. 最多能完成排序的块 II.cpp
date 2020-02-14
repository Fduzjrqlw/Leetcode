class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size() ;
        stack<int> st ;
        for (int i = 0 ; i < n ; ++i) {
            if (st.empty() || st.top() <= arr[i]) {
                st.push(arr[i]) ;
            } else {
              int u = st.top() ; st.pop() ;
                 while (!st.empty() && st.top() > arr[i]) {
                     st.pop() ;
                }
                 st.push(u) ;
             }
          }
          return st.size() ;
       }
};