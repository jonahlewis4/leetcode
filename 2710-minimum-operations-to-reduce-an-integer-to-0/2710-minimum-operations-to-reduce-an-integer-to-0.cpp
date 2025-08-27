class Solution {
public:
    int minOperations(int n) {
        int moves = 0;
        int prevDigit = -1;
        while(n > 0) {
            int dig = n % 2;
            n >>= 1;
            int nextDig = n % 2;
            
            if(nextDig == 0 && dig == 1) {
                if(prevDigit != 1) {
                    moves++;
                } else {
                    moves++;
                    nextDig = 1;
                    n += nextDig;
                    dig = 0;
                }
            }

            prevDigit = dig;
        }
        return moves;
    }
};