class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        
        int right = A.size() - 1;
        vector<int> v(A);
        
        v[right] += K;
        
        for(int i = right; i >= 0; i--){
            int num = v[i];
            if(num >= 10){
                v[i] = num % 10;
                
                if(i >= 1){
                    v[i-1] += num / 10;
                }else{
                    v.insert(v.begin(),num / 10);
                    i++;                        
                }
            }
        }
        
        return v;
    }
};