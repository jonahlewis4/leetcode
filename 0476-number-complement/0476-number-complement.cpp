class Solution {
public:
    int findComplement(int num) {
        return (num) ^ ((uint)-1 >> (__builtin_clz(num)));
    }
};