class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int total = 0;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                int comb = nums[i] ^ nums[j];
                total += __builtin_popcount(comb);
            }
        }
        return total;
    }
};