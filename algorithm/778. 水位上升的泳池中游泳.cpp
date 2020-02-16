//并查集 O(N^4)
class Solution {
public:

    int dx[5] = {0 , 1 , 0 , -1} ;
    int dy[5] = {1 , 0 , -1 , 0} ;

    int f[51 * 51] , m[51 * 51] ;

    int find_set(int u) {
        int v = u , t = m[u] ;
        while (f[v] != v) {
            v = f[v] ;
            t = max(t , v) ;
        }
        while (u != v) {
            m[u] = t ;
            int temp = f[u] ;
            f[u] = v ;
            u = temp ;
        }
        return u ;
    }

    void union_set(int u , int v) {
        if (rand() & 1) {
            f[u] = v ;
            m[u] = max(m[u] , m[v]) ;
        } else {
            f[v] = u ;
            m[v] = max(m[v] , m[u]) ;
        }
        return ;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size() ;
        for (int i = 0 ; i < n * n ; ++i) {
            f[i] = i ;
            m[i] = grid[i / n][i % n] ;
        }

        for (int t = 0 ; t < n * n ; ++t) {
            for (int i = 0 ; i < n ; ++i) {
                for (int j = 0 ; j < n ; ++j) {
                    int id1 = find_set(i * n + j) ;
                    if (m[id1] <= t) {
                        for (int d = 0 ; d < 4 ; ++d) {
                            int ii = i + dx[d] , jj = j + dy[d] ;
                            if (ii >= 0 && ii < n && jj >= 0 && jj < n) {
                                int id2 = find_set(ii * n + jj) ;
                                if (m[id2] <= t){
                                    if (id1 != id2) {
                                        union_set(id1 , id2) ;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (find_set(0) == find_set(n * n - 1)) {
                return t ;
            }
        }
        return 0 ;
    }
};

//优先队列算法 O(N^2logN)
class Solution {
public:

    const int dx[5] = {0 , 1 , 0 , -1} ;
    const int dy[5] = {1 , 0 , -1 , 0} ;

    struct node {
        int x , y , h ;
        friend bool operator <(const node &A , const node &B) {
            return A.h > B.h ;
        }
    } ;

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size() , res = 0 ;
        vector<bool> in_queue(n * n , false) ;
        priority_queue<node> pq ;
        pq.push({0 , 0 , grid[0][0]}) ;
        in_queue[0] = true ;
        while (!pq.empty()) {
            node state = pq.top() ; pq.pop() ;
            res = max(res , state.h) ;
            if (state.x == n - 1 && state.y == n - 1) {
                break ;
            }
            int x = state.x , y = state.y ;
            for (int d = 0 ; d < 4 ; ++d) {
                if (x + dx[d] >= 0 && x + dx[d] < n && y + dy[d] >= 0 && y + dy[d] < n) {
                    if (!in_queue[n * (x + dx[d]) + y + dy[d]]) {
                        in_queue[n * (x + dx[d]) + y + dy[d]] = true ;
                        pq.push({x + dx[d] , y + dy[d] , grid[x + dx[d]][y + dy[d]]}) ;
                    }
                }
            }
        }
        return res ;
    }
};