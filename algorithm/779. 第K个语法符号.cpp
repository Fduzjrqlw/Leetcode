class Solution {
public:
    int kthGrammar(int N, int K) {
        vector<int> two(N + 1 , 0) ;

        two[0] = 1 ;
        for (int i = 1 ; i <= N ; ++i) {
            two[i] = two[i - 1] << 1 ;
        }

        int rev = 0 ;
        while (K > 1) {
            if (K > two[N - 1]) {
                ++rev ;
                K -= two[N - 1] ;
            }
            --N ;
        }
        return (rev % 2) ;
    }
};