class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int allXor = 0;
        for(const int num : nums) {
            allXor ^= num;
        }

    
        int rMost = (allXor) & (-(uint)allXor);

        int xor1 = 0;
        int xor2 = 0;
        for(const int num : nums) {
            if(num & rMost){
                xor1 ^= num;
            } else {
                xor2 ^= num;
            }
        }

        return {xor1, xor2};
    }
};