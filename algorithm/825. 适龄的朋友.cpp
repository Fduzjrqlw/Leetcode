class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int n = ages.size() , res = 0 ;
        vector<int> add(121 , 0) ;
        for (int i = 0 ; i < n ; ++i) {
            add[ages[i]]++ ;
        }
        for (int i = 1 ; i <= 120 ; ++i) {
            add[i] += add[i - 1] ;
        }

        for (int i = 0 ; i < n ; ++i) {
            int l = ages[i] * 0.5 + 8 ;
            int r = ages[i] ;
            if (r >= l) {
                res += add[r] - add[l - 1] - 1 ;
            }
        }

        return res ;

    }
};