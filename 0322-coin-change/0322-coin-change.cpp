class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {        
        int smallestCoin = *min_element(coins.begin(), coins.end());

        int maxCoinsNeeded = amount / smallestCoin + 1;

        vector<int> dp(amount + 1, maxCoinsNeeded);
        dp[0] = 0;

        for(int i = 0; i < dp.size(); i++){
            for(const auto &coin : coins){
                int oldIndex = i - coin;
                if(oldIndex < 0) {
                    continue;
                }
                dp[i] = min(dp[i], dp[oldIndex] + 1);
            }
        }


        return dp.back() == maxCoinsNeeded ? -1 : dp.back();
    }
};