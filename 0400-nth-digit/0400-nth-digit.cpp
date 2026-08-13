class Solution {
public:
    int findNthDigit(int n) {
        int numReached = 1;
        int digitsPerNumber = 1;
        int num = 1;
        int mod = 10;
        while(n > digitsPerNumber) {
            n -= digitsPerNumber;
            numReached++;
            if(numReached % mod == 0) {
                digitsPerNumber++;
                mod *= 10;
            }
        } 




        //answer is nth digit after numReached
        return to_string(numReached)[n-1] - '0';
    }   
};