class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int k = max(i,j);
        string res(k+1,0);
        
        for(; k>=0; k--,i--,j--){
            int s1 = 0;
            int s2 = 0;
            
            if(i >= 0) s1 = num1[i] - '0';
            if(j >= 0) s2 = num2[j] - '0';
            
            int sum = s1 + s2 + res[k];
            
            if(sum >= 10){
                res[k] = sum - 10;
                if(k >= 1) res[k-1] += 1;
                else{
                    string leads(1,1);
                    res = leads + res;
                }
            }else{
                res[k] = sum;
            }
        }
        
        for(int i = 0; i < res.size(); i++) res[i] += '0';
        if(res[0] == '0') res = "0";
        
        return res;
    }
};