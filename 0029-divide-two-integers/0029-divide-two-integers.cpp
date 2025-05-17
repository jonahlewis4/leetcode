class Divider {
    protected: 
    bool normalize(int &dividend, int &divisor) const{
        bool positive;

        if(dividend < 0 && divisor < 0){
            positive = true;
        } else if (dividend > 0 && divisor > 0){
            positive = true;
        } else {
            positive = false;
        }

        if(dividend > 0){
            dividend = 0 - dividend;
        }
        if(divisor > 0){
            divisor = 0 - divisor;
        }
        return positive;
    }
};

class Sub :  Divider{
public:
    int divide(int dividend, int divisor){
        int quotient = 0;

        int positive = normalize(dividend, divisor);

        while(dividend <= divisor){
            quotient--;
            dividend -= divisor;
        }

        if(positive){
            quotient = 0 - quotient;
        }

        return quotient;
    }
};

class PowerSub : Divider {
public:
    int divide(int dividend, int divisor){
        int quotient = 0;

        int positive = normalize(dividend, divisor);

        int curFits = -1;
        int baseDivisor = divisor;


        auto const aggregate = [&quotient, &curFits, &dividend, &divisor, baseDivisor]() {
            quotient += curFits;
            curFits = -1;
            dividend -= divisor;
            divisor = baseDivisor;
        };


        while(dividend <= divisor){
            if(divisor < (INT_MIN >> 1)){
                aggregate();
                continue;
            }
            int nextDivisor = divisor + divisor;
            if(nextDivisor < dividend){       
                aggregate();
                divisor = baseDivisor;
            } else {
                curFits += curFits;
                divisor = nextDivisor;
            }
        }

        if(positive) {
            quotient = 0 - quotient;
        }

        return quotient;
    }
};


class Solution {
    
public:
    int divide(int dividend, int divisor) {
        //represent number in base divisor and extrapolate. 
        
        if(dividend == INT_MIN && divisor == -1){
            return INT_MAX;
        }

        return PowerSub().divide(dividend, divisor);
    }
};

