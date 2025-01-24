class Solution {
private:
public:
    int maxProfit(vector<int>& prices) {
        //maximum = 0;
        vector<vector<int>> cache;

        cache = vector<vector<int>>(2, vector<int>(prices.size() + 1, 0));
        for(int i = prices.size() - 1; i >= 0; i--){
            cache[true][i] = max(cache[true][i + 1], cache[false][i + 1] - prices[i]);
            cache[false][i] = max(cache[false][i + 1], cache[true][i + 1] + prices[i]);
        }
        return cache[true][0];
    }
};