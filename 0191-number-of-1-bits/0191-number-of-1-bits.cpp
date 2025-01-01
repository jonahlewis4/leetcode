class Solution {
public:
    int hammingWeight(int n) {
        
        //2 = 10

        int num1s = 0;
        while(n > 0){
            if ((n & 1) == 1){
                num1s++;
            }
            n = n >> 1;
        }
        return num1s;
    }
};