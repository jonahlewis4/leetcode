class Solution {
public:
    int hammingWeight(int n) {
        
        //2 = 10

        int num1s = 0;
        while(n > 0){
            n = n & (n - 1);
            num1s++;
        }
        return num1s;
    }
};