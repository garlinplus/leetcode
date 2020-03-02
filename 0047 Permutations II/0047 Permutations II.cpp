class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> v;
        std::sort(nums.begin(),nums.end());
        
        backTrack(nums,v,0);
        
        set<string> vs;
        
        vector<vector<int>> vv;
        
        for(int i = 0; i <v.size(); i++){
            string s(v[i].begin(),v[i].end());
            if(vs.find(s) == vs.end()){
                vs.insert(s);
                vv.push_back(v[i]);
            }
        }
        
        
        return vv;
    }
    
    void backTrack(vector<int>&nums,vector<vector<int>>& v,int t){
        if(t >= nums.size()){
            v.push_back(nums);
            return;
        }
        
        for(int i = t; i < nums.size(); i++){
            
            std::swap(nums[i],nums[t]);  
            backTrack(nums,v,t+1);
            std::swap(nums[i],nums[t]);
        }
        
    }
    
    std::set<int> s;
};