class Solution {
private:
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            int best = i;
            for(int j = 1; j * j <= i; j++) {
                int square = j * j;
                int calculated = dp[i - square];
                best = min(calculated + 1, best);
            }
            dp[i] = best;
        }
        return dp.back();
    }
};