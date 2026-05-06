class Solution {
public:
    long long removeZeros(long long n) {
        long long res = 0;
        while(n > 0) {
            int digit = n % 10;
            if(digit != 0) {
                res *= 10;
                res += digit;
            }
            
            n/=10;
        }

        long long res2 = 0;
        while(res > 0) {
            int digit = res % 10;
            res2 *= 10;
            res2 += digit;
            res/=10;
        }
        return res2;
    }
};