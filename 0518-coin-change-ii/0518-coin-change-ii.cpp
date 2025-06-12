class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1);
        dp.back() = 1;
        for(int r = coins.size() - 1; r >= 0; r--){
            for(int c = amount; c >= 0; c--){
                int coin = coins[r];
                int right = 0;
                if(c + coin <= amount) {
                    right = dp[c + coin];
                }
                int below = dp[c];
                long long ans = (long long)right + below;
                if(ans > INT_MAX) {
                    ans = 0;
                }
                dp[c] = ans;
            }
        }
        return dp[0];

    }
};