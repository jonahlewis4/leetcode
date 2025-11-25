class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        }
        if(x == 0){
            return true;
        }

        int numDigits = digitCount(x);
        int leftPower = pow(10, numDigits - 1);
        int rightPower = 1;


        while(leftPower >= rightPower) {
            int leftDigit = x / leftPower % 10;
            int rightDigit = x / rightPower % 10;


            if(leftDigit != rightDigit){
                return false;
            }


            leftPower /= 10;
            rightPower *= 10;
        
        }

        
        return true;
    }


    int pow(int base, int power) const {
        int res = 1;
        while(power > 0){
            res *= base;
            power--;
        }
        return res;
    }

    int digitCount(int x) const {
        int digits = 0;
        while(x > 0){
            digits++;
            x /= 10;
        }
        return digits;
    }
};