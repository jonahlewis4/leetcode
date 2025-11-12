class Solution {
public:
    int findComplement(int num) {
        return (~num) & (INT_MAX >> __builtin_clz(num));
    }
};