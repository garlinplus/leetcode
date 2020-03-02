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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
     
        if(lists.size() < 1) return nullptr;
        
        ListNode* head = lists[0];
        
        
        for(int i = 1; i < lists.size(); i++){
            
            ListNode* p2 = lists[i];
            
            while(p2){
                ListNode* p1 = head;
                ListNode* prep = nullptr;
                ListNode* p2n = p2->next;
                
                while(p1){
                    if(p1->val <= p2->val){
                       prep = p1; 
                    }else{
                        break;
                    }
                    
                    p1 = p1->next;
                }               
                
                if(prep){
                    if(p1){
                        prep->next = p2;
                        p2->next = p1;
                    }else{
                        prep->next = p2;
                        p2->next = nullptr;
                    }                    
                }else{
                    p2->next = p1;
                    head = p2;
                }
                
                 p2 = p2n;
            }
        }
        
        return head;
    }
};