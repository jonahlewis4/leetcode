class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m < n) {
            swap(m, n);
        }

        vector<int> dp(n + 1, 0);
        dp.back() = 1;

        for(int r = m - 1; r >= 0; r--){
            for(int c = n - 1; c >= 0; c--){
                dp[c] = dp[c] + dp[c + 1];   
            }
            dp.back() = 0;
        }
        return dp[0];


    }
};