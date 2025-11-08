class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        vector<int> dp(3, 0);

        for(int h = 0; h < costs.size(); h++) {
            vector<int> newDp(3, 0);
            for(int color = 0; color < 3; color++){
                int best = INT_MAX;
                for(int i = 0; i < 3; i++){
                    if(i == color) {
                        continue;
                    }
                    int prev = dp[i];
                    best = min(prev, best);
                }

                newDp[color] = best + costs[h][color];
            }
            dp = newDp;
        }

        return min({dp.front(), dp[1], dp.back()});
    }
};