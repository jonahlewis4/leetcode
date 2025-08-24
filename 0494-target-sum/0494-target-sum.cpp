class Solution {

public:

    int subSumCount(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp.back() = 1;
        for(int i = nums.size() - 1; i >= 0; i--) {
            for(int sum = 0; sum <= target; sum++) {
                int below = dp[sum];
                int newSum = sum + nums[i];
                int withNewSum = newSum > target ? 0 : dp[newSum];

                dp[sum] = below + withNewSum;
            }
        }
        return dp.front();
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        int remaining = sum - target;
        if(remaining % 2 != 0) {
            return 0;
        }
        int sumTarget = remaining / 2;
        if(sumTarget < 0) {
            return false;
        }
    

        return subSumCount(nums, sumTarget);
    }
};