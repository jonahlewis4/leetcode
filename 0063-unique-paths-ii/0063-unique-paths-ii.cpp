class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<long long> dp(obstacleGrid[0].size(), 0);
        
        for(int i = obstacleGrid.size() - 1; i >= 0; i--){
            long long right = 0;
            for(int j = dp.size() - 1; j >= 0; j--){
                //get right
                //get below
                if(i == obstacleGrid.size() - 1 && j == dp.size() - 1){
                    if(obstacleGrid[i][j] == 1){
                        dp[j] = 0;
                    } else {
                        dp[j] = 1;
                    }
                    right = dp[j];
                    continue;
                }
                if(obstacleGrid[i][j] == 1){
                    dp[j] = 0;
                    right = dp[j];
                    continue;
                }
                int below = i + 1 < obstacleGrid.size() ? dp[j] : 0;
                dp[j] = (long long)below + right;
                right = dp[j];
            }
        }
        return dp[0];
    }
};