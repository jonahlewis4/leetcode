class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int finalDigit = k % 10;
        switch (finalDigit) {
            case 1:
            case 3:
            case 7:
            case 9:{
                int m = 1;
                int steps = 1;
                while(m % k != 0) {
                    m *= 10;
                    m++;
                    m %= k;
                    steps++;
                }
                return steps;
            }
            default: 
                return -1;
        }
    }
};