class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        int nx = getN(x,bound);
        int ny = getN(y,bound);
            
        set<int> s;
        vector<int> res;
        vector<int> vy;
        
        int yp = 1;
        for(int i = 0; i <= ny; i++){
            if(yp > bound){
                ny = i-1;
                break;
            }
            
            vy.push_back(yp);
            yp *= y;
        }
        
        
        int xp = 1;
        int sum = 0;
        for(int i = 0; i <= nx; i++){
            if(xp > bound) break;
            for(int j = 0; j <= ny; j++){
                sum = xp + vy[j];
                if(sum <= bound){
                    if(s.find(sum) == s.end()) s.insert(sum);
                }
                else{
                    break;
                }
            }
            
            xp *= x;
        }
        
        
        res.assign(s.begin(),s.end());
        
        
        return res;
    }
    
    int getN(int n,int b){
        if(n == 1) return 0;
        
        int r = 0;
        int nm = 1;
        
        while(b > nm){
            nm *= n;
            r++;
        }
        
        return r;
    }
};