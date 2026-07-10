class Solution {
public:
    double myPow(double x, int n2) {
        long long n = (long long)n2;
        bool negative = n < 0;
        n = abs(n);
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