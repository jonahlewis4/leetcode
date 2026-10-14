class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> sums;
        sums[0] = -1;
        int sum = 0;
        int bestLen = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                sum++;
            } else {
                sum--;
            }

            if(sums.contains(sum)) {
                bestLen = max(bestLen, i - sums[sum]);
            } else {
                sums[sum] = i;
            }
        }

        return bestLen;
    }
};