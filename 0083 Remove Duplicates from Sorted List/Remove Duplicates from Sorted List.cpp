class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p1 = head;
        ListNode *p2;
            
        while(p1){
            p2 = p1->next;
            
            if(!p2) break;
            
            while(p2 && (p1->val == p2->val)){
                p2 = p2->next;
            }
            
            p1->next = p2;
            p1 = p1->next;
        }
        
        return head;
    }
};