class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        
        int pow = 31;
        while(n > 0){
            int digit = n & 1;
            res += (digit << pow);
            pow--;
            n = n >> 1;
        }
        return res;
    }
};