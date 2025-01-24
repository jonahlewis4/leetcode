class Solution {
private:
public:
    int maxProfit(vector<int>& prices) {
        //maximum = 0;
        int prevBuy = 0;
        int prevSell = 0;

        for(int i = prices.size() - 1; i >= 0; i--){
            int buy = max(prevBuy, prevSell - prices[i]);
            int sell = max(prevSell, prevBuy + prices[i]);
            prevBuy = buy;
            prevSell = sell;
        }
        return prevBuy;
    }
};