class Solution {

    
public:
    double new21Game(int n, int k, int maxPts) {
        if(k == 0) {
            return 1;
        }
        int numGuaranteedVictory = max(n - k + 1, 0);
        if(numGuaranteedVictory >= maxPts) {
            return 1;
        }
        int numUnsure = n - numGuaranteedVictory;
        vector<double> dp(numUnsure + 1, 0);

        double sum = numGuaranteedVictory;

        for(int i = dp.size() - 1; i >= 0; i--) {
           
            dp[i] = sum / maxPts;
            sum += dp[i];
            if(i + maxPts < k) {
                sum -= dp[i + maxPts];
            } else if (i + maxPts <= n) {
                sum -= 1;
            }

        }
        return dp.front();
    }
};