class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        array<int, 32> digCount = {};
        int minLen = INT_MAX;
        while( r < nums.size()) {
            //add new r values.
            array<bool, 32> digits = bitset(nums[r]);
            for(int i = 0; i < digits.size(); i++){
                digCount[i] += digits[i];
            }
            while(l <= r && bitset_eval(digCount) >= k){
                minLen = min(minLen, r - l + 1);
                if(minLen == 1){
                    return 1;
                }
                array<bool, 32> digits = bitset(nums[l]);
                for(int i = 0; i < digits.size(); i++){
                    digCount[i] -= digits[i];
                }
                l++;
            }
            r++;             
        }
        return minLen == INT_MAX ? -1 : minLen;
    }


    array<bool, 32> bitset(int num){
        array<bool, 32> res = {}; 
        for(int i = 0; i < 32; i++){
            res[32 - i - 1] = num & 1;
            num >>= 1;
        }
        return res;
    }
    unsigned int bitset_eval(const array<int, 32> & bitset){
        unsigned int res = 0;
        for(int i = 0; i < bitset.size(); i++){
            res <<= 1;
            res |= min(bitset[i], 1);
        }
        return res;
    }
    

};