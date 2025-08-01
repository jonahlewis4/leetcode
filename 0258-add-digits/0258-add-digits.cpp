class Solution {
public:
    int addDigits(int num) {
        while(num > 9) {
            int n2 = num;
            num = 0;
            while(n2 > 0) {
                num += n2 % 10;
                n2 /= 10;
            }
        }
        return num;
    }
};