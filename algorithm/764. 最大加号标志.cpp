class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        int res = 0 ;
        vector<map<int,int>> L(N) , R(N) , U(N) , D(N) ;

        for (int i = 0 ; i < mines.size() ; ++i) {
            int x = mines[i][0] , y = mines[i][1] ;
            L[x][-y]++ ;
            R[x][y]++ ;
            D[y][x]++ ;
            U[y][-x]++ ;
        }
        for (int i = 0 ; i < N ; ++i) {
            for (int j = 0 ; j < N ; ++j) {
                while (i + res < N && j + res < N && i - res >= 0 && j - res  >= 0) {
                    auto lter = R[i].lower_bound(j) ;
                    if (lter != R[i].end() && lter->first <= j + res) {
                        break ;
                    }
                    auto rter = L[i].lower_bound(-j) ;
                    if (rter != L[i].end() && (-rter->first) >= (j - res)) {
                        break ;
                    }
                    auto dter = D[j].lower_bound(i) ;
                    if (dter != D[j].end() && dter->first <= i + res) {
                        break ;
                    }
                    auto uter = U[j].lower_bound(-i) ;
                    if (uter != U[j].end() && (-uter->first) >= i - res) {
                        break ;
                    }
                    ++res ;
                }
                if (i == 1 && j == 1) {
                    cout << res << endl ;
                }
            }
        }
        return res ;
    }
};