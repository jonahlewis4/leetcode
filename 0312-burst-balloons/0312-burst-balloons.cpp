class Solution {
    template <typename T>
    void wrap1s(vector<T>& nums) const {
        nums.resize(nums.size() + 2);
        for(int i = nums.size() - 2; i >= 1; i--){
            nums[i] = nums[i - 1];
        }
        nums[0] = 1;
        nums.back() = 1;
    }
public:

    int maxCoins(vector<int>& nums) {
        wrap1s(nums);
        vector<vector<int>> dp(nums.size() - 1, vector<int>(nums.size(), 0));

        for(int r = dp.size() - 2; r >= 0; r--){
            for(int c = dp[r].size() - (dp.size() - r) + 1; c < dp[r].size(); c++){
                int best = 0;
                for(int k = r + 1; k < c; k++){
                    int left = dp[r][k];
                    int right = dp[k][c];
                    int local = left + right + nums[r] * nums[k] * nums[c];
                    best = max(best, local);
                }
                dp[r][c] = best;
            }
        }

        return dp[0].back();
    }
};