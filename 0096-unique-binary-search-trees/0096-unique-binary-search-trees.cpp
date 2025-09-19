class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp.front() = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            int k = i - 1;
            for(int l = 0; l <= k; l++) {
                int r = k - l;
                int lVal = dp[l];
                int rVal = dp[r];
                int res = lVal * rVal;
                dp[i] += res;
            }
        }
        return dp.back();
    }
    
    
};