class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        vector<long long> dp(skill.size(), 0);
        for(int i = 0; i < mana.size(); i++) {
            long long prev = dp.front();
            for(int j = 0; j < dp.size() - 1; j++) {
                dp[j] = max((long long)prev + skill[j] * mana[i], dp[j + 1]);
                prev = dp[j];
            }
            dp.back() = (long long)prev + skill.back() * mana[i];
            for(int j = dp.size() - 2; j >= 0; j--) {
                dp[j] = dp[j + 1] - skill[j + 1] * mana[i];
            }
        }
        return dp.back();
    }
};