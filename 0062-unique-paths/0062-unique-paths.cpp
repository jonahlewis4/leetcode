class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<tuple<int, int>> dirs {
            {0, 1},
            {1, 0},
        };

        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = 1;

        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                for(const auto & dir : dirs) {
                    auto [xOffset, yOffset] = dir;
                    int newR = r + xOffset;
                    int newC = c + yOffset;

                    if(newR >= m || newC >= n){
                        continue;
                    }
                    dp[newR][newC] += dp[r][c] ;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};