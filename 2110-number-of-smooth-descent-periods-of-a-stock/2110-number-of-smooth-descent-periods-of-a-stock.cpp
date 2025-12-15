class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long total = 0;
        long streak = 0;
        for(int i = 1; i < prices.size(); i++) {
            int prev = prices[i - 1];
            int cur = prices[i];
            if(cur == prev - 1) {
                streak++;
                total += streak;
            } else {
                streak = 0;
            }
        }

        return total + prices.size();
    }
};