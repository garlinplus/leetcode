class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        if(!head || !head->next) return false;
        
        ListNode *p1 = head;
        ListNode *p2 = head->next;
        
        while(p1 != p2){
            if(!p2 || !p2->next)
                return false;
            
            p1 = p1->next;
            p2 = p2->next->next;
        }
        
        return true;
    }
};