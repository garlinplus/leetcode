class Solution {
public:
    string multiply(string num1, string num2) {        
        int p = 0;
        string res;
        for(int i = num1.size() - 1; i >= 0; i--,p++){
            int n1 = num1[i] - '0';
            string s(num2.size(),0);
            for(int j = num2.size() - 1; j >= 0; j--){
               int n2  = num2[j] - '0';
               int m = n1 * n2 + s[j];
                if( m >= 10){
                    s[j] = m % 10;
                    if(j >= 1) s[j -1] = m / 10;
                    else{
                        string tmp(1,m / 10);
                        s = tmp + s;
                    }       
                }else{
                    s[j] = m;
                }
            }         
            if(res.empty()) res = s;
            else{
                string zeros(p,0);
                s += zeros;
                int j = res.size() - 1;
                int m = s.size() - 1;
                int k = std::max(j,m);
                string ss(k + 1,0);
                for(; k >= 0;k--,j--,m--){
                    int n1 = 0;
                    int n2 = 0;
                    if(j >= 0) n1 = res[j]; 
                    if(m >= 0) n2 = s[m];  
                    int sum = n1 + n2 + ss[k];
                    if(sum >= 10){
                        ss[k] = sum - 10;
                        if(k >= 1) ss[k-1] = 1;
                        else{
                            string tmp;
                            tmp.push_back(1);
                            ss = tmp + ss;
                        }
                    }else{
                        ss[k] = sum;
                    }
                }
                res = ss;              
            }
        }
        if(res[0] == 0) return "0";
        for(int j = 0;j < res.size();j++) res[j] += '0';
        return res;
    }
};