class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> nodeSet;
        
        ListNode *p = head;
        while(p){
            if(nodeSet.find(p) == nodeSet.end()){
                nodeSet.insert(p);
            }else{
                break;
            }
            p = p->next;
        }
        
        return p;
    }
};