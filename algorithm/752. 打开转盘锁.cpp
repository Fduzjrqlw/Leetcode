class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string,int> uid ;
        unordered_map<int,string> uname ;
        string temp ;
        int cnt = 0 ;
        for (int i = 0 ; i < 10 ; ++i) {
            for (int j = 0 ; j < 10 ; ++j) {
                for (int k = 0 ; k < 10 ; ++k) {
                    for (int l = 0 ; l < 10 ; ++l) {
                        temp = "" ;
                        temp += (char) (i + '0') ;
                        temp += (char) (j + '0') ;
                        temp += (char) (k + '0') ;
                        temp += (char) (l + '0') ;
                        uid[temp] = ++cnt ;
                        uname[cnt] = temp ;
                    }
                }
            }
        }
        vector<int> dist(cnt + 1 , 0x7f7f7f) ;
        vector<bool> dead(cnt + 1 , false) ;
        vector<bool> vis(cnt + 1 , false) ;
        for (int i = 0 ; i < deadends.size() ; ++i) {
            dead[uid[deadends[i]]] = true ;
        }
        if (dead[1]) {
            return -1 ;
        }
        queue<int> q ;
        dist[1] = 0 ; vis[1] = true ; q.push(1) ;
        while (!q.empty()) {
            int u = q.front() ; q.pop() ;
            string s = uname[u] ;
            for (int i = 0 ; i < 4 ; ++i) {
                string t = s ;
                if (t[i] > '0') {
                    t[i] -= 1 ;
                    
                    if (!dead[uid[t]] && !vis[uid[t]]) {
                        dist[uid[t]] = dist[u] + 1 ;
                        vis[uid[t]] = true ;
                        q.push(uid[t]) ;
                    }
                    t[i] += 1 ;
                } else {
                    t[i] = '9' ;
                    if (!dead[uid[t]] && !vis[uid[t]]) {
                        dist[uid[t]] = dist[u] + 1 ;
                        vis[uid[t]] = true ;
                        q.push(uid[t]) ;
                    }
                    t[i] = '0' ;
                }
                if (t[i] < '9') {
                    t[i] += 1 ;
                    if (!dead[uid[t]] && !vis[uid[t]]) {
                        dist[uid[t]] = dist[u] + 1 ;
                        vis[uid[t]] = true ;
                        q.push(uid[t]) ;
                    }
                    t[i] -= 1 ;
                } else {
                    t[i]  = '0' ;
                    if (!dead[uid[t]] && !vis[uid[t]]) {
                        dist[uid[t]] = dist[u] + 1 ;
                        vis[uid[t]] = true ;
                        q.push(uid[t]) ;
                    }
                    t[i] = '9' ;
                }
            }
        }
        if (dist[uid[target]] == 0x7f7f7f) {
            return -1 ;
        }
        return dist[uid[target]] ;
    }
};