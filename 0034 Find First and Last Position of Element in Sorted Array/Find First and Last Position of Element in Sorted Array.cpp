class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        if(nums.size() == 0)return vector<int>{-1,-1};
        
        while(left <= right){
            mid = (left + right) / 2;
            
            if(nums[mid] == target) break;
            
            if(nums[mid] < target){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        
        int min = mid;
        int max = mid;
        if(nums[mid] == target){
            while((min >= 0) && (nums[min] == target)) min--;
            while((max < nums.size()) && (nums[max] == target)) max++;
            
            min++;
            max--;
        }else{
            min = -1;
            max = -1;
        }
        
        vector<int> v{min,max};
        
        return v;
    }
};