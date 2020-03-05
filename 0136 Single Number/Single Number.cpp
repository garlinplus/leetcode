class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int i = 0;
        int j = 0;
        
        while(i < nums.size()){
            
            j = i+1;
            if(j == nums.size()) break;
            
            if(nums[i] != nums[j]){
                break;
            }else{
                 while(j < nums.size() && nums[i] == nums[j]){
                    j++;
                }               
            }

            i = j;
        }
        
        return nums[i];
    }
};