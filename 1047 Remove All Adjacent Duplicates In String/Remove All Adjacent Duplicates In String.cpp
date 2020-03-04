class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> stk;
        
        for(int i = 0; i < S.size(); i++){
            if(!stk.empty()){
                if(stk.top() == S[i]){
                    stk.pop();
                    continue;
                }
            }
            
            stk.push(S[i]);
        }
        
        string res(stk.size(),0);
        
        for(int i = res.size() - 1; i >= 0; i--){
            res[i] = stk.top();
            stk.pop();
        }
        
        return res;
    }
};