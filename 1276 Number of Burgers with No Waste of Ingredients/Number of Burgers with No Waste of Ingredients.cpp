class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        vector<int> res;
        //4x+2y = t
        //x + y = c
        //2y = 4c -t,2x = t - 2c
        //x = t / 2 -c,y=2c - t/2
        
        if(tomatoSlices % 2 == 0){
            tomatoSlices /= 2;
            int x = tomatoSlices - cheeseSlices;
            int y = 2 * cheeseSlices - tomatoSlices;
            if(x >= 0 && y>= 0){
                res.push_back(x);
                res.push_back(y);                
            }
        }
        
        return res;
    }
};