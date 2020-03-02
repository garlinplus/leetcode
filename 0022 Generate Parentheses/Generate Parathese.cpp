class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string s;
        vector<string> v;
        
        for(int i = 0; i < n; i++) s = s + "()";
        
        backTrack(s,v,0);
        
        return v;
    }
    
    void backTrack(string& s, vector<string>& v, int t){
        
        if(t >= s.size()){
            stack<char> stk;
            for(int i = 0; i < s.size(); i++){
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
        
        set<char> sets;
        
        for(int i = t; i < s.size(); i++){
            swap(s[t],s[i]);
            
            if(sets.find(s[t]) == sets.end()){
                sets.insert(s[t]);
                backTrack(s,v,t+1);
            }
            
            swap(s[t],s[i]);
        }
        
    }
};