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
    ListNode* middleNode(ListNode* head) {
        ListNode *fast = head->next , *slow = head ;
        while (fast != NULL) {
            slow = slow->next ;
            fast = fast->next ;
            if (fast == NULL) {
                break ;
            }
            fast = fast->next ;
        }
        return slow ;

    }
};