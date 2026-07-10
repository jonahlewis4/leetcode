class Solution {
public:
    double myPow(double x, int n2) {
        bool negative = n2 < 0;
        unsigned int n = n2 > 0 ? n2 : -(n2 + 1) + (unsigned int)1;
        double result = 1;
        while(n > 0) {
            if(n & 1) {
                result *= x;
            }
            x *= x;
            n>>=1;
        }
        if(negative){
            result = 1/result;
        }
        return result;
    }
};