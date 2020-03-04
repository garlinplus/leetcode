class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int k = max(i,j);
        
        string res(k+1,0);
        
        for(;k >= 0; k--,i--,j--){
            int s1 = 0;
            int s2 = 0;
            
            if(i >= 0) s1 = a[i] - '0';
            if(j >= 0) s2 = b[j] - '0';
            
            int sum = s1 + s2 + res[k];
            
            if(sum >= 2){
                res[k] = sum % 2;
                if(k >= 1) res[k -1] = sum >> 1;
                else{
                    string leads(1,sum >> 1);
                    res = leads + res;
                }
            }else{
                res[k] = sum;
            }
        }
        
        for(int i = 0; i < res.size(); i++) res[i] += '0';
        
        return res;
    }
};