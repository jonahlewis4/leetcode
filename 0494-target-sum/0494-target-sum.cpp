class Solution {
private:
    
public:
    int findTargetSumWays(const vector<int>& nums, int target) {
        
        
        int sum = 0;
        for(const auto & num : nums){
            sum += num;
        }
        
        if(abs(target) > sum) {
            return 0;
        }

        vector<int> dp(2 * sum + 1, 0);



        dp[target + sum] = 1;
        auto &_dp = dp;
        for(int r = nums.size(); r >= 1; r--){
            vector<int> newDp(dp.size(), 0);
            for(int c = -sum; c <= sum; c++){
                if(dp[c + sum] > 0){
                    int num = nums[r - 1];

                    int left = c - num;
                    int right = c + num;

                    if(left >= -sum && left <= sum){
                        newDp[left + sum] = dp[c + sum] + newDp[left + sum];
                    }

                    if(right >= -sum && right <= sum){
                        newDp[right + sum] = dp[c + sum] + newDp[right + sum];
                    }
                }
            }
            dp = newDp;
        }


        return dp[sum];
    }
};