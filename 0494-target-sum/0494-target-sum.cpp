class Solution {
    class Base {
        protected:
            vector<int>& nums;
            int target;
            Base(vector<int>& nums, int target) : nums(nums), target(target){}

        public:
            virtual int findTargetSumWays() = 0;
    };

    class Recursion : Base{
        public:
            Recursion(vector<int>& nums, int target) : Base(nums, target){}
            int findTargetSumWays() override  {
                return dfs(0, 0);
            }
            int dfs (int i, int val) const {
                if(i == nums.size() && val == target) {
                    return 1;
                }
                if(i >= nums.size()) {
                    return 0;
                }
                int add = dfs(i + 1, val + nums[i]);
                int sub = dfs(i + 1, val - nums[i]);

                return add + sub;
            }
    };

    class Memoization : Base {
        private:
            vector<vector<int>> dp;
            int sum;
        public:
        Memoization(vector<int>& nums, int target) : Base(nums, target) {
            sum = 0;
            for(const auto & num : nums){
                sum += num;
            }
            dp.resize(nums.size(), vector<int>(sum * 2 + 1, -1));
        }
        int findTargetSumWays() {
            if(sum < abs(target)){
                return false;
            }
            return dfs(0, 0);
        }
        int dfs(int i, int val) {
            if(i == nums.size() && val == target) {
                return 1;
            }
            if(i >= nums.size()) {
                return 0;
            }
            if(dp[i][val + sum] != -1){
                return dp[i][val + sum];
            }
            
            int add = dfs(i + 1, val + nums[i]);
            int sub = dfs(i + 1, val - nums[i]);
            int res = add + sub;
            dp[i][val + sum] = res;
            return res;
        }
    };
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return Memoization(nums, target).findTargetSumWays();
    }
};