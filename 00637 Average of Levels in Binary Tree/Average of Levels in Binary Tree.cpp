class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root) return {};
        
        vector<double> v;
        vector<int> levelCountV;
        
        v.push_back(root->val);
        levelCountV.push_back(1);
        
        dfs(root,v,levelCountV,1);
        
        for(int i = 0; i < v.size(); i++){
            v[i] /= levelCountV[i];
        }
        
        return v;
    }
    
    void dfs(TreeNode *root,vector<double>& v,vector<int> &levelCountV,int h){
        if(!root ||(!root->left && !root->right)) return;
        
        if(v.size() < h + 1){
            v.push_back(0);
            levelCountV.push_back(0);
        }
        
        if(root->left) {
            v[h] += root->left->val; 
            levelCountV[h]++;
        }
        
        if(root->right) {
            v[h] += root->right->val;  
            levelCountV[h]++;
        }
        
        dfs(root->left,v,levelCountV,h+1);
        dfs(root->right,v,levelCountV,h+1); 
    }
};