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
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_map<int,int> mp ;
        for (int i = 0 ; i < G.size() ; ++i) {
            mp[G[i]]++ ;
        }

        int res = 0 ;

        ListNode *pt = head ;

        while (pt != NULL) {
            if (mp.find(pt->val) != mp.end() && (pt->next == NULL || mp.find(pt->next->val) == mp.end()))
                ++res ;
            pt = pt->next ;
        }
        return res ;
    }
};