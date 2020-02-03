/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int n = 0 ;
        ListNode*p = root ;
        while(p) {
            ++n ;
            p = p->next ;
        }
        vector<ListNode*> res(k) ;
        vector<int> sz(k , 0) ;
        if (n % k == 0) {
            for (int i = 0 ; i < k ; ++i)
                sz[i] = n / k ;
        } else {
            for (int i = 0 ; i < n % k ; ++i) 
                sz[i] = n / k + 1 ;
            for (int i = n % k ; i < k ; ++i) 
                sz[i] = n / k ;
        }
        ListNode *q = root ; p = root ;
        for (int i = 0 ; i < k ; ++i) {
            if (i != 0 && q) {
                q->next = NULL ;
            }
            res[i] = p ;
            for (int j = 0 ; p && j < sz[i] ; ++j) {
                q = p ; p = p->next ;
            }
        }
        return res ;
    }
};