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
        offset = sum;
        dp.resize(2 * sum + 1, vector<int>(nums.size(), INT_MAX));

        return recurse(0, 0);
    }
};