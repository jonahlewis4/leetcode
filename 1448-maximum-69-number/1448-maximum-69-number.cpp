class Solution {
public:
    int maximum69Number (int num) {
        int pow = 1;
        int num2 = num;
        int additive = 0;
        while(num2 > 0 ){
            int dig = num2 % 10;
            num2 /= 10;
            if(dig == 6) {
                additive = pow * 3;
            }

            pow *= 10;
        }

        return num + additive;
    }
};