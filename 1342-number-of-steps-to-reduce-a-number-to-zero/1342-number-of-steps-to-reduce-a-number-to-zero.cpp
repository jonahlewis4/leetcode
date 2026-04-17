class Solution {
public:
    int numberOfSteps(int num) {
        //14 = 8 + 4 + 2 + 0
        //14 = 1110
        //0 = div by 2 = 1 operation
        //1 = sub 1, div by 2 = 2 operations
        //
        //14/2 = 7
        //7-1=6
        //6/2=3
        //3-1=2
        //2/2=1
        //1-1=0

        //8 = 1000
        //5 = 101
        //5-1=4
        //4/2=2
        //2/2=1
        //1-1=0
        
        if(num == 0) {
            return 0;
        }

        int ones = __builtin_popcount(num);
        int digits = 32 - __builtin_clz(num);
        int zeroes = digits - ones;
        return ones * 2 + zeroes - 1;
    }
};