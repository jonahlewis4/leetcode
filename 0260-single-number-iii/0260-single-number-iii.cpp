class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int allXor = 0;
        for(const int num : nums) {
            allXor ^= num;
        }

        int lz = __builtin_clz(allXor);
        int digNum = 32 - lz;
        int lMost = 1 << (digNum - 1);

        int xor1 = 0;
        int xor2 = 0;
        for(const int num : nums) {
            if(num & lMost){
                xor1 ^= num;
            } else {
                xor2 ^= num;
            }
        }

        return {xor1, xor2};
    }
};