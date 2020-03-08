class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> v;
        
        v.push_back(1);
        
        for(int i = 1; i <= rowIndex; i++){
            
            for(int j = i - 1; j >= 1; j--){
                v[j] = v[j-1] + v[j];
            }
            
            v.push_back(1);
        }
    
        return v;
    }
};