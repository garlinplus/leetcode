class Solution {
public
    vectorstring generateParenthesis(int n) {
        string s;
        vectorstring v;
        
        for(int i = 0; i  n; i++) s = s + ();
        
        backTrack(s,v,0);
        setstring sets(v.begin(),v.end());
        v.assign(sets.begin(),sets.end());
        
        return v;
    }
    
    void backTrack(string& s, vectorstring& v, int t){
        if(t = s.size()){
            stackchar stk;
            for(int i = 0; i  s.size(); i++){
                if(!stk.empty()){
                    if(stk.top() = '(' && s[i] == ')'){
                        stk.pop();
                        continue;
                    }
                }
                
                stk.push(s[i]);
            }
            
            if(stk.empty()){
                v.push_back(s);
            }
            
            return;
        }
        
        for(int i = t; i  s.size(); i++){
            swap(s[t],s[i]);
            backTrack(s,v,t+1);
            swap(s[t],s[i]);
        }
        
    }
};