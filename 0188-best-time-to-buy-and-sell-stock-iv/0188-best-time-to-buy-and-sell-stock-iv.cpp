class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> bestPrice(k + 1, INT_MAX);
        vector<int> bestProfit(k + 1, 0);

        for(const int price : prices) {
            for(int i = 1; i <= k; i++) {
                int bestBuy = min(price - bestProfit[i - 1], bestPrice[i]);
                bestPrice[i] = bestBuy;
                int bestSell = max(bestProfit[i], price - bestBuy);
                bestProfit[i] = bestSell;
            }
        }
        
        return bestProfit.back();
    }
};