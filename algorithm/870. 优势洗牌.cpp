class Solution {
public:

    struct node {
        int p , val ; 
    } ;

    static bool cmp(const node& A , const node& B) {
        return A.val > B.val ;
    }

    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        int n = A.size() ;
        vector<int> res(n , 0) ;
        vector<node> numsA , numsB ;
        for (int i = 0 ; i < n ; ++i) {
            numsA.push_back({i , A[i]}) ;
            numsB.push_back({i , B[i]}) ;
        }
        sort(numsA.begin() , numsA.end() , cmp) ;
        sort(numsB.begin() , numsB.end() , cmp) ;
        int l = 0 , r = n - 1 , j = 0 ;
        while (l <= r) {
            if (numsA[l].val > numsB[j].val) {
                res[numsB[j].p] = numsA[l].val ;
                ++l ;
            } else {
                res[numsB[j].p] = numsA[r].val ;
                --r ;
            }
            ++j ;
        }
        return res ;
    }
};