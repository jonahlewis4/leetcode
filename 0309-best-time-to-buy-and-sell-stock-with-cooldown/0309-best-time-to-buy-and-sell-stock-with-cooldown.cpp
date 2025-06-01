class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int twoBuysAgo = 0;
        int oneBuyAgo = 0;
        int oneSellAgo = 0;
        for(int i = prices.size() - 1; i >= 0; i--){
            int worth = prices[i];

            //sell scenarios
            int sellNow = worth + twoBuysAgo;
            int sellLater = oneSellAgo;

            int bestSell = max(sellNow, sellLater);
            
            //buy scenarios
            int buyNow = oneSellAgo - worth;
            int buyLater = oneBuyAgo;

            int bestBuy = max(buyNow, buyLater);

            //set values for next iteration

            twoBuysAgo = oneBuyAgo;
            oneBuyAgo = bestBuy;
            oneSellAgo = bestSell;
        }

        //we can only buy starting out, so get oneBuyAgo
        return oneBuyAgo;
    }
};