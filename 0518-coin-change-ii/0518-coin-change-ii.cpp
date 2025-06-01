class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<long long>> dp(amount + 1, vector<long long>(coins.size(), 0));
        
        const auto & compute = [amount, &coins, &dp](int curAmount, int coinI) -> long long {
            if(amount == curAmount){
                return 1;
            }
            if(curAmount > amount){
                return 0;
            }
            if(coinI >= coins.size()){
                return 0;
            }
            return dp[curAmount][coinI];
        };

        const auto & skip = [amount, &coins, &dp, &compute](int amountI, int coinI){
            return compute(amountI, coinI + 1);
        };

        const auto & use = [amount, &coins, &dp, &compute](int amountI, int coinI){
            return compute(amountI + coins[coinI], coinI);
        };

        for(int amountI = dp.size() - 1; amountI >= 0; amountI--){
            for(int coinI = dp[0].size() - 1; coinI >= 0; coinI--){
                int useCoin = use(amountI, coinI);
                int skipCoin = skip(amountI, coinI);
                dp[amountI][coinI] = (long long)(useCoin) + skipCoin;
            }
        }

        return dp[0][0];
    }
};