class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* p1 = head;
        ListNode* p2 = nullptr;
        
        while(p1){
            
            p2 = p1;
            for(int i = 1; i < k; i++) {
                if(p2) p2 = p2->next;
                else{
                    break;;
                }
            } 
            
            if(!p2) break;
            
            ListNode* left = p1;
            // ListNode* right = p2;

            int m = k;
            while(m > 1){
                ListNode* in = left;
                for(int i = 1; i < m; i++){
                    if(in) in = in->next;
                }
                
                int tmp = left->val;
                left->val = in->val;
                in->val = tmp;
                
                left = left->next;
                m -= 2;
            }
            
            p1 = p2->next;
        }
        
        return head;
    }
};