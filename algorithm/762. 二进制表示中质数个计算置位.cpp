class Solution {
public:

    unordered_map<int,int> prime ;

    int count_bit(int x) {
        int c = 0 ;
        while (x) {
            ++c ;
            x -= (x & (-x)) ;
        }
        return c ;
    }

    int countPrimeSetBits(int L, int R) {
        for (int i = 2 ; i <= 32 ; ++i) {
            bool flag = true ;
            for (int j = 2 ; j * j <= i ; ++j) {
                if (i % j == 0) {
                    flag = false ;
                    break ;
                }
            }
            if (flag) {
                prime[i] = 1 ;
            }
        }
        int res = 0 ;
        for (int i = L ; i <= R ; ++i) {
            if (prime[count_bit(i)] == 1) {
                ++res ;
            }
        }
        return res ;
    }
};