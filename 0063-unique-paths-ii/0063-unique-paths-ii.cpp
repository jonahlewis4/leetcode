class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<long long>> dp(obstacleGrid.size(), vector<long long>(obstacleGrid[0].size(), 0));
        
        for(int i = dp.size() - 1; i >= 0; i--){
            for(int j = dp[i].size() - 1; j >= 0; j--){
                //get right
                //get below
                if(i == dp.size() - 1 && j == dp[i].size() - 1){
                    if(obstacleGrid[i][j] == 1){
                        dp[i][j] = 0;
                    } else {
                        dp[i][j] = 1;
                    }
                    continue;
                }
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                    continue;
                }
                int right = j + 1 < dp[i].size() ? dp[i][j + 1] : 0;
                int left = i + 1 < dp.size() ? dp[i + 1][j] : 0;

                dp[i][j] = (long long)left + right;
            }
        }
        return dp[0][0];
    }
};