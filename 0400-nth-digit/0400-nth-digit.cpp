class Solution {
public:
    int findNthDigit(int n) {
        if(n < 10) {
            return n;
        }
        n -= 9;
        int currentNumber = 10;
        int digitsPer = 2;
        int numsInSection = 90;

        while((long long) numsInSection * digitsPer < n) {
            n -= numsInSection * digitsPer;
            currentNumber *= 10;
            numsInSection *= 10;
            digitsPer++;
        }

        n--;
        currentNumber += n / digitsPer;
        int remainder = n % digitsPer;

        return to_string(currentNumber)[remainder] - '0';
    }   
};