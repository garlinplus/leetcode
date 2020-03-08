class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        
        return dfs(root,0);
    }
    
    int dfs(TreeNode* root,int flag){
        if(!root){
            return 0;
        }
        
        int sum = 0;
        
        if(flag){
            if(!root->left && !root->right){
                sum = root->val;
            }    
        }
        
        return sum + dfs(root->left,1) + dfs(root->right,0);
    }
};