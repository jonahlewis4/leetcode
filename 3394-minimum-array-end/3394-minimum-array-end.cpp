class Solution {
public:
    long long minEnd(int n, int x) {
        //strictly increasing array of size n that ands to x.

        

        //go from right to left in x
        //go from right to left in n - 1;

        n--;
        
        //if x is 0 just move over
        //if x digit is 1 continue

        long long res = x;
        long twoPow = 1;
        while(n > 0){
            int xDigit = x & 1;
            if(x > 0 && xDigit == 1){
                
            } else {
                int nDigit = n & 1;
                n >>= 1;
                if(nDigit == 1){
                    res |= twoPow;
                }
            }
            x >>= 1;
            twoPow <<= 1;
        }

        return res;
    }
};