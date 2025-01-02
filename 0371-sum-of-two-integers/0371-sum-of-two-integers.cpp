class Solution {
public:
    int getSum(int a, int b) {
        if(b == 0){
            return a;
        }
        int noCarry = a ^ b;
        int carries = (a & b) << 1;

        return getSum(noCarry, carries);
    }
};
