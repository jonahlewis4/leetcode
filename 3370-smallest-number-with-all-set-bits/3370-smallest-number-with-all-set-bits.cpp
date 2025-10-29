class Solution {
public:
    int smallestNumber(int n) {
        int numBits = 32 - __builtin_clz(n);
        int next =  1 << numBits;
        return next - 1;
    }
};