/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        int n = wordlist.size() ;
        vector<vector<int>> sim(n , vector<int>(n , 0)) ;
        vector<bool> vis(n , false) ;

        for (int i = 0 ; i < n ; ++i) {
            for (int j = 0 ; j < n ; ++j) {
                for (int k = 0 ; k < wordlist[i].length() ; ++k) {
                    if (wordlist[i][k] == wordlist[j][k]) {
                        ++sim[i][j] ;
                    }
                }
            }
        }
        
        int p = -1 ;
        while (true) {
            int temp = n + 1 ;
            for (int i = 0 ; i < n ; ++i) {
                if (!vis[i]) {
                    vector<int> cnt(7 , 0) ;
                    for (int j = 0 ; j < n ; ++j) {
                        if (!vis[j] && i != j) {
                            cnt[sim[i][j]]++ ;
                        }
                    }
                    int t = 0 ;
                    for (int d = 0 ; d <= 6 ; ++d) {
                        t = max(t , cnt[d]) ;
                    }
                    if (t < temp) {
                        temp = t ;
                        p = i ;
                    }
                }
            }
            cout << wordlist[p] << " " << temp << endl ;
            int x = master.guess(wordlist[p]) ;
            if (x == 6) {
                return ;
            }
            vis[p] = true ;
            for (int i = 0 ; i < n ; ++i) {
                if (!vis[i]) {
                    if (sim[p][i] != x) {
                        vis[i] = true ;
                    }
                }
            }
        }

    }
};