class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        for(int i = dp.size() - 2; i >= 0; i--) {
            int minMoves = dp.size();
            for(int j = i + 1; j < nums.size() && j <= i + nums[i]; j++){
                minMoves = min(minMoves, dp[j]);
            }
            dp[i] = minMoves + 1;
        }
        return dp.front();
    }
};