class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1; // Base case: 1 way to make amount 0

        for (int coin : coins) {
            for (int amt = coin; amt <= amount; ++amt) {
                dp[amt] = min((long long)INT_MAX, dp[amt] + (long long)dp[amt - coin]);
            }
        }

        return dp[amount];
    }
};
