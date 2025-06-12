class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned int> dp(amount + 1);
        dp.back() = 1;
        for(int r = coins.size() - 1; r >= 0; r--){
            for(int c = amount; c >= 0; c--){
                int coin = coins[r];
                unsigned int right = 0;
                if(c + coin <= amount) {
                    right = dp[c + coin];
                }
                unsigned int below = dp[c];
                unsigned int ans = right + below;
                if(ans > INT_MAX) {
                    ans = 0;
                }
                dp[c] = ans;
            }
        }
        return dp[0];

    }
};