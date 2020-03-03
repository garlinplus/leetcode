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
    ListNode* swapPairs(ListNode* head) {
        if(!head) return nullptr;
        if(!head->next) return head;
        
        ListNode* p1 = head;
        ListNode* p2 = nullptr;
        
        while(p1){
            p2 = p1->next;
            
            if(!p2) break;
            
            int tmp = p1->val;
            p1->val = p2->val;
            p2->val = tmp;
            
            p1 = p2->next;
        }
        
        return head;
    }
};