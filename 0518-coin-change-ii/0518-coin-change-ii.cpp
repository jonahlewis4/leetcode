class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<long long> dp(amount + 1, 0);
        dp.front() = 1;

        for(int coinIdx = coins.size() - 1; coinIdx >= 0; coinIdx--) {
            for(int amt = 1; amt <= amount; amt++){
                int below = dp[amt];
                int leftIdx = amt - coins[coinIdx];
                if(leftIdx < 0) {
                    dp[amt] = below;
                } else {
                    int left = dp[leftIdx];
                    dp[amt] = (long long)below + left;
                }
            }
        }

        return dp.back();
    }
};