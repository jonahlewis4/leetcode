class Solution {
private:
    vector<int> days;
    vector<int> costs;
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int finalDay = days[days.size() - 1];
        vector<int> dp(finalDay + 1, -1);
        int dayIdx = 0;
        for(int i = 1; i <= finalDay; i++){
            if(i < days[dayIdx]){
                dp[i] = dp[i - 1];
            } else {
                dayIdx++;
                dp[i] = min({
                    costs[0] + (i - 1 >= 0 && dp[i - 1] >= 0 ? dp[i - 1] : 0),
                    costs[1] + (i - 7 >= 0 && dp[i - 7] >= 0 ? dp[i - 7] : 0),
                    costs[2] + (i - 30 >= 0 && dp[i - 30] >= 0 ? dp[i - 30] : 0), 
                });
            }
        }
        return dp[finalDay];
    
    }
};