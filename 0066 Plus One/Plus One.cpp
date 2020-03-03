class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>v(digits);
        
        long num = 0;
        
        int right = v.size() - 1;
        
        v[right] += 1;

        
        for(int i = right; i >= 0; i--){
            if(i > 0 && v[i] > 9){
                v[i - 1] += 1;
            }
        }
        
        for(int i = 1; i <= right; i++){
            if(v[i] > 9) v[i] -= 10;
        }
        
        if(v[0] > 9){
            v[0] -= 10;
            v.insert(v.begin(),1);
        }
        
        return v;
    }
};