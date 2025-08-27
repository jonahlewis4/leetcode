class Solution {

    
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> dp(n + 1, 0);
        dp.back() = 0;
        double sum = 0;

        for(int i = n; i >= 0; i--) {
            if(i >= k) {
                dp[i] = 1;
            } else if(i + maxPts > n){
                dp[i] = sum / maxPts;
            } else {
                dp[i] = sum / maxPts;
            }

            sum += dp[i];
            if(i + maxPts <= n) {
                sum -= dp[i + maxPts];
            }

        }
        return dp.front();
    }
};