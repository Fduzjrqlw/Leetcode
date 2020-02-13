class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int res = 0 ;
        for (int i = 0 ; i < row.size() ; ++i) {
            if (i % 2 == 0) {
                if ((row[i] ^ 1) != row[i + 1]) {
                    ++res ;
                    for (int j = i + 1 ; j < row.size() ; ++j) {
                        if (row[j] == (row[i] ^ 1)) {
                            swap(row[i + 1] , row[j]) ;
                            break ;
                        }
                    }
                }
            }
        }
        return res ;
    }
};