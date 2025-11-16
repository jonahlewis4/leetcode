class Solution {
public:
    int numSub(string s) {
        int streak = 0;
        int res = 0;

        int MOD = (int)1e9 + 7;
        for(const char c : s) {
            if(c == '1') {
                streak++;
                res += streak;
                res %= MOD;
            } else {
                streak = 0;
            }
        }

        return res;
    }
};