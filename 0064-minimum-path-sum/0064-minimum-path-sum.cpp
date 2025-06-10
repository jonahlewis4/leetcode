class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rc = grid.size(); 
        int cc = grid[0].size();
       

        vector<int> dp(cc + 1, INT_MAX);
        dp.back() = 0;
        for(int r = rc - 1; r >= 0; r--){
            for(int c = cc - 1; c >= 0; c--){
                int below = dp[c];
                int right = dp[c+1];
                int amt = grid[r][c];
                dp[c] = min(below, right) + amt;
            }
            dp.back() = INT_MAX;
        }
        return dp[0];
    }
};