class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy = -prices[0];
        int sell = 0;
        for(int i = 1; i < prices.size(); i++) {
            int price = prices[i];

            sell = max(buy + price - fee, sell);
            buy = max(sell - price, buy);


        }

        return sell;
    }
};