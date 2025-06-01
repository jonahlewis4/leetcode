class Solution {
    private:

    int calc(int amount,const vector<int> &coins, const vector<vector<int>> &dp, int curAmount, int coinI) const {
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
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount + 1, vector<int>(coins.size(), 0));
        for(int amountI = dp.size() - 1; amountI >= 0; amountI--){
            for(int coinI = dp[0].size() - 1; coinI >= 0; coinI--){
                int useCoin = calc(amount, coins, dp, amountI + coins[coinI], coinI);
                int skipCoin = calc(amount, coins, dp, amountI, coinI + 1);
                if((long long) useCoin + skipCoin > INT_MAX){
                    continue;
                }
                dp[amountI][coinI] = useCoin + skipCoin;
            }
        }

        return dp[0][0];
    }
};