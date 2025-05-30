class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<tuple<int, int>> dirs {
            {0, 1},
            {1, 0},
        };

        vector<int> dp(n, 0);

        dp[0] = 1;

        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                if(c + 1 < n){
                    dp[c + 1] += dp[c];
                }
            }
        }

        return dp.back();

    }
};