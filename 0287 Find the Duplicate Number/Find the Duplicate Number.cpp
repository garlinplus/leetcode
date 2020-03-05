class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = nums[0];
        int slow = nums[0];
        
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
         }while(fast != slow);
        
        int p1 = nums[0];
        int p2 = slow;
        
        while(p1 != p2){
            
            p1 = nums[p1];
            p2 = nums[p2];
        }
        
        return p1;
    }
};