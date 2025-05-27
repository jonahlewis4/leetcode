class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(const auto & num : nums){
            sum += num;
        }

        if(sum % 2 == 1){
            return false;
        }

        int target = sum / 2;

        return subsetSum(nums, target);
    }

    bool subsetSum(vector<int>& nums, int target) {
        vector<bool> dp(target + 1, 0);
        dp[0] = true;
        for(const auto & num : nums){
            for(int i = dp.size() - 1; i >= 0; i--){
                int prev = i - num;
                if(prev < 0){
                    continue;
                } 

                if(dp[prev]){
                    dp[i] = true;
                }
            }
        }
        return dp[target];

    }
};