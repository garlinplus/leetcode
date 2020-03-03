class Solution {
public:
    vector<string> letterCombinations(string digits) {
        std::map<char,string> m = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        vector<string> res;
        vector<string> v;
        
        if(digits.size() < 1) return {};
        
        for(int i = 0; i < digits.size();i++){
            if(m.find(digits[i]) != m.end()) v.push_back(m[digits[i]]);
        }
        
        string s;
        backTrack(v,res,s,0);
        
        return res;
    }
    
    
    void backTrack(vector<string>&v,vector<string>& res,string& s,int t){
        
        if(t == v.size()){
            if(s.size() == v.size())
                res.push_back(s);
            return;
        }
        
        for(int i = t; i < v.size(); i++){
            for(int j = 0; j < v[i].size(); j++){
                s.push_back(v[i][j]);
                backTrack(v,res,s,i+1);
                s.pop_back();
            }
        }
    }
};