class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp.back() = 1;
        for(const auto & coin : coins) {
            for(int amt = amount - coin; amt >= 0; amt--){
                int cur = dp[amt];
                int after = dp[amt + coin];

                long long sum = (long long)cur + after;
                if(sum > INT_MAX){
                    sum = 0;
                }
                dp[amt] = sum;
            }
        }

        return dp[0];
    }
};