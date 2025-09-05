class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int k = 1;
        while(true) {
            long long x = num1 - ((long long)k * num2);

            if(num2 >= 0) {
                if(x < 0) {
                    return -1;
                }
                if(k > x) {
                    return -1;
                }
            }

            if(__builtin_popcountll(x) <= k) {
                return k;
            }
            k++;
        }
        return -1;
    }
};

