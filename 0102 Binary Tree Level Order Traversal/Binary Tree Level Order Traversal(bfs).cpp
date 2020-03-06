class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        return bfs(root);
    }
    
    vector<vector<int>> bfs(TreeNode *root){
        
        if(!root) return {};
        
        queue<TreeNode*> q;
        vector<vector<int>> v;
        
        q.push(root);
        q.push(nullptr);
        
        v.push_back({});
        
        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();
                        
            if(!node){
                if(q.empty()) break;
                q.push(nullptr);
                v.push_back({});
                continue;                   

            }else{
                v.back().push_back(node->val);
            }
            
            if(node->left) 
                q.push(node->left);
            
            if(node->right) 
                q.push(node->right);
        }
        
        return v;
    }
};