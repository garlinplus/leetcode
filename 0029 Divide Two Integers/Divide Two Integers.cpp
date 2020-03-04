class Solution {
public:
    int divide(int dividend, int divisor) {

        int count = 0;
        int negFlag1 = 1;
        int negFlag2 = 1;
        int ndd = 0;
        
        if(divisor == 0) return INT_MAX;
        
        if(dividend < 0){
            negFlag1 = -1;
            if(dividend == INT_MIN)
            {
                dividend = INT_MAX;
                ndd = 1;
            }else{
                dividend = -dividend;
            }
        }
        
        if(divisor < 0){
            negFlag2 = -1;
            if(divisor == INT_MIN){
                divisor = INT_MAX;
            }else{
                divisor = -divisor;
            }
        }
        
        if(dividend < divisor){
            return 0;
        }else if(dividend == divisor){
            if(negFlag1 == 1 && negFlag2 == -1){
                if(divisor == INT_MAX) return 0;
                return -1;
            }else{
                return (negFlag1 * negFlag2);
            }
        }
        
        if(divisor == 1 && dividend == INT_MAX && negFlag1 == -1){
            if(negFlag2 == 1) return INT_MIN;
            if(negFlag2 == -1) return INT_MAX;
        }
        
        int div = dividend / divisor;
        int rem = dividend % divisor;
        if(ndd){
            rem += ndd;
            
            if(rem >= divisor) div += 1;
        }

        
        div = div * negFlag1 * negFlag2;
        
        return div;
    }
};