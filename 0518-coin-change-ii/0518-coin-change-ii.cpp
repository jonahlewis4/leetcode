class Solution {
    private:

    long long calc(int amount,const vector<int> &coins, const vector<vector<long long>> &dp, int curAmount, int coinI) const {
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
        vector<vector<long long>> dp(amount + 1, vector<long long>(coins.size(), 0));
        for(int amountI = dp.size() - 1; amountI >= 0; amountI--){
            for(int coinI = dp[0].size() - 1; coinI >= 0; coinI--){
                int useCoin = calc(amount, coins, dp, amountI + coins[coinI], coinI);
                int skipCoin = calc(amount, coins, dp, amountI, coinI + 1);
                dp[amountI][coinI] = (long long)(useCoin) + skipCoin;
            }
        }

        return dp[0][0];
    }
};