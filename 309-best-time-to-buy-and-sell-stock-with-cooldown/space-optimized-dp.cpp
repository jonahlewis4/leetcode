//not as ellegant as neetcode but i came up with this and so I'm happy with it

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //we want to track the previous sell,
        //the previous buy
        //and previous from two ago buy. two ago buy is if we sell, we need to wait.

        int previousSell = 0;
        int previousBuy = 0;
        int previous2xBuy = 0;

        //loop through each in the list backwards.

        //calculate buy and sell.

        //buy will be previous sell minus amount
        //cooldown will be previous buy

        //sell will be previous2x buy plus amount
        //cooldown will be previous sell.

        for(int i = prices.size() - 1; i >= 0; i--){
            int previousBuyTemp = previousBuy;
            for(int j = 0; j < 2; j++){
                if(j == 0){
                    int newBuy = previousSell - prices[i];
                    int cooldown = previousBuy;
                    previousBuy = std::max(newBuy, cooldown);
                } else {
                    int newSell = previous2xBuy + prices[i];
                    int cooldown = previousSell;
                    previousSell = std::max(newSell, cooldown);
                }
            }
            previous2xBuy = previousBuyTemp;
        }
        return previousBuy;
    }
};