class Solution {

    
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> dp(n + maxPts);
        for(int i = n + 1; i < dp.size(); i++) {
            dp[i] = 0;
        }
        for(int i = k; i <= n; i++) {
            dp[i] = 1;
        }
        for(int i = k - 1; i >= 0; i--) {
            double total = 0;
            if(i == k - 1) {
                for(int card = 1; card <= maxPts; card++) {
                    int next = i + card;
                    double prob = dp[next];
                    total += prob;
                }
                total /= maxPts;
                dp[i] = total;
            } else {
                total = dp[i + 1] * maxPts;
                total -= dp[i + maxPts + 1];
                total += dp[i + 1];
                total /= maxPts;
                dp[i] = total;
            }
        }
        return dp.front();
    }
};