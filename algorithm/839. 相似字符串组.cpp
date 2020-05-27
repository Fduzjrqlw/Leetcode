class Solution {
public:

    int fa[2001] ;
    bool vis[2001] ;


    int findSet(int u) {
        int v = u ;
        while (v != fa[v]) {
            v = fa[v] ;
        }
        while (u != fa[u]) {
            int t = fa[u] ;
            fa[u] = v ;
            u = t ;
        }
        return u ;
    }

    void merge(int u , int v) {
        if (rand() & 1) {
            fa[u] = v ;
        } else fa[v] = u ;
        return ;
    }

    int numSimilarGroups(vector<string>& A) {
        int n = A.size() ;
        int res = 0 ;
        for (int i = 0 ; i < n ; ++i) {
            fa[i] = i ;
        }
        for (int i = 0 ; i < n ; ++i) {
            for (int j = i + 1 ; j < n ; ++j) {
                int cnt = 0 ;
                for (int l = 0 ; l < A[i].length() ; ++l) {
                    if (A[i][l] != A[j][l]) {
                        ++cnt ;
                    }
                }
                if (cnt <= 2) {
                    int u = findSet(i) , v = findSet(j) ;
                    if (u != v)
                        merge(u , v) ;
                }
            }
        }

        for (int i = 0 ; i < n ; ++i) {
            if (!vis[findSet(i)]) {
                vis[fa[i]] = true ;
                ++res ;
            }
        }
        return res ;


    }
};