class Solution {
    vector<vector<int>> dirs = {
        {0, 1},
        {1, 0},
        {-1, 0},
        {0, -1}
    };
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));

        int maxAns = 0;
        for(int r = dp.size() - 1; r >= 0; r--) {
            for(int c = dp[0].size() - 1; c >= 0; c--) {
                int longestFromHere = dfs(r, c, dp, matrix);
                maxAns = max(maxAns, longestFromHere);
            }
        }
        return maxAns;
    }

    int dfs(int r, int c, vector<vector<int>>& dp, const vector<vector<int>>& matrix) {
    

        if(dp[r][c] != -1){
            return dp[r][c];
        }

        int val = 1;


        for(const auto & dir : dirs) {
            int rOffset = dir[0];
            int cOffset = dir[1];
            int newR = r + rOffset;
            int newC = c + cOffset;

            if(newR < 0 || newC < 0 || newR >= matrix.size() || newC >= matrix[newR].size()){
                continue;
            }
            if(matrix[newR][newC] <= matrix[r][c]){
                continue;
            }

            val = max(val, 1 + dfs(newR , newC, dp, matrix));
        }

        dp[r][c] = val;
        return val;

        
    }
};