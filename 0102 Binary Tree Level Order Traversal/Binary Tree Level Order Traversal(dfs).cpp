class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        
        vector<vector<int>> v;
        v.push_back({root->val});
        
        dfs(root,v,1);
        
        return  v;
    }
    
    void dfs(TreeNode *root,vector<vector<int>> &v,int level){
        if(!root || (!root->left && !root->right)) return;
        
        if(v.size() < level + 1){
            v.push_back({});
        }
        
        if(root->left){
            v[level].push_back(root->left->val);
        }
        
        if(root->right){
            v[level].push_back(root->right->val);
        }
        
        dfs(root->left,v,level+1);
        dfs(root->right,v,level+1);
    }
};