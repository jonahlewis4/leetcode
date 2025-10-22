class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp.front() = 1;

        for(int coinIdx = coins.size() - 1; coinIdx >= 0; coinIdx--) {
            for(int amt = coins[coinIdx]; amt <= amount; amt++){
                int below = dp[amt];
                int leftIdx = amt - coins[coinIdx];
                int left = dp[leftIdx];
                dp[amt] = min((long long) INT_MAX , (long long)below + left);
            }
        }

        return dp.back();
    }
};