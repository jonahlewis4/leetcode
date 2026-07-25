class Solution {
public:
    int maxProduct(int n) {
        int d1 = 0;
        int d2 = 0;
        while(n > 0) {
            int digit = n % 10;
            n /= 10;

            if(digit > d1) {
                d2 = d1;
                d1 = digit;
            } else if (digit > d2) {
                d2 = digit;
            }
        }

        return d1 * d2;
    }
};