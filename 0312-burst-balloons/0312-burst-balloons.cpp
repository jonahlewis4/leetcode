class Solution {
    vector<int> wrapped(const vector<int>& nums) {
        vector<int> res(nums.size() + 2);
        res[0] = 1;
        res.back() = 1;
        for(int i = 0; i < nums.size(); i++){
            res[i + 1] = nums[i];
        }
        return res;
    }
public:
    int maxCoins(vector<int>& _nums) {
        vector<int> nums = wrapped(_nums);
        vector<vector<int>> dp(nums.size() - 1, vector<int> (nums.size(), 0));

        for(int r = dp.size() - 1; r >= 0; r--) {
            for(int c = r + 2; c < dp[r].size(); c++){
                int best = 0;
                for(int m = r + 1; m <= c - 1; m++){
                    int coins = nums[m] * nums[r] * nums[c];
                    int local = coins + dp[r][m] + dp[m][c];
                    best = max(local, best);
                }
                dp[r][c] = best;
            }
        }
        return dp[0].back();
    }
};