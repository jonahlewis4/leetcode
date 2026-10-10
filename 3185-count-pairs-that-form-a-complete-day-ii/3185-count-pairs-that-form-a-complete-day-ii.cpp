class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long res = 0;
        array<int, 24> amts;
        amts.fill(0);
        for(int hour : hours) {
            hour %= 24;
            int compliment = 24 - hour;
            compliment %= 24;

            res += amts[compliment];
            amts[hour]++;
        }

        return res;
    }
};