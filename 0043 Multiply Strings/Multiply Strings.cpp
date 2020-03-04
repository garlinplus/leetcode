class Solution {
public:
    string multiply(string num1, string num2) {
        
        int n1 = 0;
        int n2 = 0;
        vector<string> v;
        for(int i = num1.size() - 1; i >= 0; i--){
            n1 = num1[i] - '0';
            
            string s(num2.size(),0);
            for(int j = num2.size() - 1; j >= 0; j--){
               n2  = num2[j] - '0';
                
               int m = n1 * n2 + s[j];
                
                if( m >= 10){
                    s[j] = m % 10;
                    
                    if(j >= 1)
                        s[j -1] = m / 10;
                    else{
                        string tmp(1,m / 10);
                        s = tmp + s;
                    }       
                }else{
                    s[j] = m;
                }
            }
            
            // for(int j = 0; j < s.size(); j++) s[j] += '0';
            
            v.push_back(s);
        }
        
        // string res;
        // for(int i = 0; i < v.size();i++) res = res + "," + v[i];
        string res = v[0];
        
        int i = 1;
        while(i < v.size()){
            string s = v[i];
             int k = s.size() - 1;
             int right = res.size() - 1 - i;
             for(int j = right; j >= 0; j--,k--){
                 int sum = s[k] + res[j];
                 if(sum >= 10){
                     res[j] = sum - 10;
                     if(j >= 1){
                         res[j-1] += 1;
                     }else{
                         s[k] = 10;
                     }
                 }else{
                      res[j] = sum;
                }
             }
            
             k++;
             int p = k;
             while(k > 0){
                 if(s[k] >= 10){
                    s[k] -= 10;
                     s[k-1] += 1;
                 }    
                 k--;
             }
            
             string tmp;
             if(s[0] >= 10){
                 s[0] -= 10;
                 tmp.push_back(1);
             }
            
             res = tmp + s.substr(0,p) + res;
             i++;
         }
        
        k++;
         while(k > 0){
             if(s[k] >= 10){
                ss[k] -= 10;
                ss[k-1] = s[k-1] + 1;
             }
         }
        
         int flag = 0;
         for(int i = 0; i < res.size();i++){
             if(res[i] != 0){
                 flag = 1;
             }
             res[i] += '0';
         } 
        
         if(!flag) res = "0"
            return res;
    }
};