    void backTrackWithSet(vector<int>&nums,vector<vector<int>>&v,int t){
        
        if(t >= nums.size()){
            v.push_back(nums);
            return;
        }
        
        set<int> s;
        
        for(int i = t; i < nums.size(); i++){
            
            std::swap(nums[i],nums[t]); 
            
            if(s.find(nums[t]) == s.end()){
                s.insert(nums[t]);
                backTrackWithSet(nums,v,t+1);
            }
            
            std::swap(nums[i],nums[t]);
        }
    }