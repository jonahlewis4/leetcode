class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        vector<int> dp(3, 0);

        for(int h = 0; h < costs.size(); h++) {
            vector<int> newDp(3, 0);
            newDp[0] = costs[h][0] + min(dp[1], dp[2]);
            newDp[1] = costs[h][1] + min(dp[0], dp[2]);
            newDp[2] = costs[h][2] + min(dp[0], dp[1]);
            dp = newDp;
        }

        return min({dp.front(), dp[1], dp.back()});
    }
};