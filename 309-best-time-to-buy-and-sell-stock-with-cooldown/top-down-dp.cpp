class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int** x = new int*[2]; //allocate two pointers for the rows in cache
        for(int i = 0; i < 2; i++)
        {
            x[i] = new int[prices.size()]; //allocate prices size num elements for each array in each row.
            for(int j = 0; j < prices.size(); j++){
                x[i][j] = -1; //initialize to -1 to indicate not cached
            }
        }


        return dfs(x, 0, true, prices);


        for(int i = 0; i < 2; i++){
            delete x[i];
        }
        delete x;
    }

    int dfs(int** cache, int i, bool buying, vector<int>& prices){
        if(i >= prices.size()){
            return 0;
        }
        if (cache[boolHash(buying)][i] != -1){
            return cache[boolHash(buying)][i];
        }
        int cooldown = dfs(cache, i + 1, buying, prices);

        if(buying){
            int buy = dfs(cache, i + 1, false, prices) - prices[i];
            cache[boolHash(buying)][i] = max(buy, cooldown);
        } else {
            int sell = dfs(cache, i + 2, true, prices) + prices[i];
            cache[boolHash(buying)][i] = max(sell, cooldown);
        }
        return cache[buying][i];

    }
    int boolHash(bool b) {
        if(b){
            return 1;
        }
        return 0;
    }
};