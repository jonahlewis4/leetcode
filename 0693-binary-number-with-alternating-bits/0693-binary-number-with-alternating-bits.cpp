class Solution {
public:
    bool hasAlternatingBits(int n) {
        int lz = __builtin_clz(n);
        uint shiftAmt = 32 - lz;
        uint mask = ((uint)1 << shiftAmt) - 1;

        int oneZero = 0xAAAAAAAA & mask;
        int zeroOne = 0x55555555 & mask;

        
        // cout<<oneZero<<endl;
        // cout<<zeroOne<<endl;

        return n == oneZero || n == zeroOne;
    }
};