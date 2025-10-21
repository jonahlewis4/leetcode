class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp.front() = 0;
        for(int i = 1; i <= amount; i++) {
            for(const int coin : coins) {
                int newIdx = i - coin;
                if(newIdx < 0) {
                    continue;
                }
                if(dp[newIdx] == INT_MAX) {
                    continue;
                }
                dp[i] = min(dp[i], dp[newIdx] + 1);
            } 
        }
        return dp.back() == INT_MAX ? -1 : dp.back();
    }
};