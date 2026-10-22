class Solution {
    static bool isPerfectSquare(int x) {
        int factor = sqrt(x);
        if(factor * factor == x) {
            return true;
        }
        return false;
    }
public:
    bool judgeSquareSum(int c) {
        for(int a = 0; a <= sqrt(c/2); a++) {
            int bSquared = c - (a * a);
            if(isPerfectSquare(bSquared)) {
                return true;
            }
        }
        return false;
    }
};