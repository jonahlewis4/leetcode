class Solution {
private:
    vector<vector<int>> cache;
public:
    int maxProfit(vector<int>& prices) {
        //maximum = 0;
        cache = vector<vector<int>>(2, vector<int>(prices.size(), INT_MIN));
        return dfs(prices, 0, true);
    }
    int dfs(vector<int> & prices, int i, bool buying){
        if(i >= prices.size()){
            return 0;
        }
        if(cache[buying][i] != INT_MIN){
            return cache[buying][i];
        }
        if(buying){
            int buy = dfs(prices, i + 1, false) - prices[i];
            int skip = dfs(prices, i + 1, true);
            int res = max(buy, skip);
            cache[true][i] = res;
            return max(buy, skip);
        } else {
            int sell = dfs(prices, i + 1, true) + prices[i];
            int skip = dfs(prices, i + 1, false);
            int res = max(sell, skip);
            cache[false][i] = res;
            return max(sell, skip);
        }
    }
};