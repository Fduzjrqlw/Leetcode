class MyLinkedList {
public:
    /** Initialize your data structure here. */

    struct LinkNode {
        int val ;
        LinkNode* next , *prev ;
    } *head , *tail ;

    MyLinkedList() {
        head = new LinkNode() ;
        tail = new LinkNode() ;
        head->val = 0 ; head->next = tail ; head->prev = NULL ;
        tail->val = 0 ; tail->next = NULL ; tail->prev = head ;
        
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        LinkNode *pt = head->next ;
        int cnt = 0 ;
        while (pt != tail) {
            ++cnt ;
            if (cnt == index + 1) {
                break ;
            }
            pt = pt->next ;
        }
        if (cnt == index + 1) {
            return pt->val ;
        }
        return -1 ;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        LinkNode* npt = new LinkNode() ;
        npt->val = val ;
        npt->next = head->next ; head->next->prev = npt ; npt->prev = head ;head->next = npt ;
        return ;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        LinkNode *npt = new LinkNode() ;
        npt->val = val ;
        npt->next = tail ; tail->prev->next = npt ; npt->prev = tail->prev ; tail->prev = npt ;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index <= 0) {
            addAtHead(val) ;
            return ;
        }
        LinkNode* pt = head->next ;
        int cnt = 0 ;
        while (pt != tail) {
            ++cnt ;
            if (cnt == index) {
                break ;
            }
            pt = pt->next ;
        }
        if (cnt < index) {
            return ;
        }
        LinkNode* npt = new LinkNode() ;
        npt->val = val ;
        npt->next = pt->next ; npt->prev = pt ;
        pt->next->prev = npt ; pt->next = npt ;
        return ;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0) 
            return ;
        LinkNode* pt = head->next ;
        int cnt = 0 ;
        while (pt != tail) {
            ++cnt ;
            if (cnt == index + 1) 
                break ;
            pt = pt->next ;
        }
        if (cnt != index + 1) 
            return ;
        LinkNode* temp = pt->prev ;
        temp->next = pt->next ;
        pt->next->prev = temp ;
        delete pt ;
        return ;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */