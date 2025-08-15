class Solution {

public:
    

    bool isPowerOfFour(int n) {
        if(n == 1) {
            return true;
        }
        if(n == 2) {
            return false;
        }
        if(n <= 0) {
            return false;
        }
        if(1073741824 % n != 0) {
            return false;
        }
        if(log2(n) % 2 == 1) {
            return false;
        }
        return true;

    }
    static int log2(int n) {
        return 31 - __builtin_clz(n);
    }
};
