class Solution {
public:
    int rob(vector<int>& nums) {
        
        if(nums.size() < 1) return 0;
        if(accumulate(nums.begin(),nums.end(),0) <= 0) return 0;
        
        vector<int> m(nums.size(),0);
        
        return dfs(nums,m,0);
    }
    
    int dfs(vector<int>& v,vector<int>& m,int t){
        if(t >= v.size()) return 0;

        if(m[t] > 0){
            return m[t];
        }
        
        m[t] = max(v[t] + dfs(v,m,t+2), dfs(v,m,t+1));
        
        return m[t]; 
    }
};