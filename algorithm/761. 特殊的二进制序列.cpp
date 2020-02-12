class Solution {
public:

    static int cmp(const string &A , const string &B) {
        return A > B ;
    }

    void dfs(int l , int r , string &S) {
        if (l >= r) {
            return ;
        }
        vector<pair<int,int>> pos ;
        int cnt = 0 , startPos = l ;
        for (int i = l ; i <= r ; ++i) {
            if (S[i] == '1') {
                cnt += 1 ;
            } else cnt -= 1 ;
            if (cnt == 0) {
                pos.push_back(make_pair(startPos , i)) ;
                startPos = i + 1 ;
            }
        }
        if (pos.size() == 1) {
            dfs(l + 1 , r - 1 , S) ;
            S[l] = '1' ;
            S[r] = '0' ;
        } else {
            for (int i = 0 ; i < pos.size() ; ++i) {
                dfs(pos[i].first , pos[i].second , S) ;
            }
            vector<string> temp ;
            for (int i = 0 ; i < pos.size() ; ++i) {
                temp.push_back(S.substr(pos[i].first , pos[i].second - pos[i].first + 1)) ;
            }
            sort(temp.begin() , temp.end() , cmp) ;
            string tmp = "" ;
            for (int i = 0 ; i < temp.size() ; ++i) {
                tmp += temp[i] ;
            }
            for (int i = 0 ; i < tmp.length() ; ++i) {
                S[l + i] = tmp[i] ;
            }
        }
    }

    string makeLargestSpecial(string S) {
        int l = S.length() ;
        dfs(0 , l - 1 , S) ;
        return S ;
    }
};