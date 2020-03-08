class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        if(numRows < 1) return {};
        
        vector<vector<int>> v;
        v.resize(numRows);
        
        v[0].push_back(1);
        
        for(int i = 1; i < numRows; i++){
            
            v[i].push_back(1);
            
            for(int j = 1; j < i; j++){
                
                int tmp = v[i-1][j-1] + v[i-1][j];
                
                v[i].push_back(tmp);
            }
            
            v[i].push_back(1);
        }
        
        
        return v;
    }
};