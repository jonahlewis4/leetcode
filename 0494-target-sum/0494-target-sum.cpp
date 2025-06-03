class Solution {
private:
    vector<int> nums;
    int target;
    vector<vector<int>> dp;
    int offset;
    int recurse(int i, int cur) {
        if(i == nums.size()){
            if(cur == target){
                return 1;
            }
            return 0;
        }

        
        auto &_dp = dp;
        if(dp[cur + offset][i] != INT_MAX){
            return dp[cur + offset][i];
        }

        int minus = recurse(i + 1, cur - nums[i]);
        int pos = recurse(i + 1, cur + nums[i]);


        dp[cur + offset][i] = minus + pos;
        return minus + pos;
    }
public:
    int findTargetSumWays(const vector<int>& _nums, int target) {
        
        this->target = target;
        nums = _nums;
        
        int sum = 0;
        for(const auto & num : nums){
            sum += num;
        }
        
        if(abs(target) > sum) {
            return 0;
        }

        offset = sum;
        dp.resize(nums.size() + 1, vector<int>(2 * sum + 1, 0));



        dp[nums.size()][target + sum] = 1;
        auto &_dp = dp;
        for(int r = nums.size(); r >= 1; r--){
            for(int c = -sum; c <= sum; c++){
                if(dp[r][c + sum] > 0){
                    int num = nums[r - 1];

                    int left = c - num;
                    int right = c + num;

                    if(left >= -sum && left <= sum){
                        dp[r - 1][left + sum] = dp[r][c + sum] + dp[r - 1][left + sum];
                    }

                    if(right >= -sum && right <= sum){
                        dp[r - 1][right + sum] = dp[r][c + sum] + dp[r - 1][right + sum];
                    }
                }
            }
        }


        return dp[0][sum];
    }
};