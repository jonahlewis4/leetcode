class Solution {
    bool isGood(int n) {
        bool change = false;
        while(n > 0) {
            int digit = n % 10;
            n/=10;

            switch (digit) {
                case 0:
                case 1:
                case 8:
                    break;
                case 2:
                case 5:
                case 6:
                case 9:
                    change = true;
                    break;
                default:
                    return false;
            }
        }

        return change;
    }
public:
    int rotatedDigits(int n) {
        int res = 0;
        for(int i = 1; i <= n; i++) {
            if(isGood(i)){
                res++;
            }
        }
        return res;
    }
};