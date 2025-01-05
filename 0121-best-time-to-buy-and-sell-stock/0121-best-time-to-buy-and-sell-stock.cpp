class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int min = prices[0]; 
        int i = 0;
        while(i < prices.size()){
            maxProfit = max(maxProfit, prices[i] - min);
            min = std::min(prices[i], min);
            i++;
        }
        return maxProfit;
    }
};