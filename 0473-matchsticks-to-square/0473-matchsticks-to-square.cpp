class Solution {
    int sideLength;
    bool r(const vector<int>& matchsticks, int curLen, int mask) {
        if(mask == (1 << matchsticks.size())-1){
            return true;
        }
        if(dp[mask] != 2) {
            return dp[mask];
        }
        // if(dp[curLen][curSide][mask] != 2){
        //     return dp[curLen][curSide][mask];
        // }

        for(int i = 0; i < matchsticks.size(); i++){
            int pos = (1<<i);
            bool used = (mask & pos);
            if(used) {
                continue;
            }
            int newLen = curLen + matchsticks[i];
            if(newLen > sideLength) {
                continue;
            }
            newLen %= sideLength;
            int newMask = (mask | pos);
            bool attempt = r(matchsticks, newLen, newMask);
            if(attempt) {
                dp[mask] = true;
                return true;
            }
        }

        dp[mask] = false;
        return false;

        
    }
    vector<char> dp;
public:
    bool makesquare(vector<int>& matchsticks) {
        int perim = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(perim % 4 != 0) {
            return false;
        }

        sideLength = perim / 4;
        dp.resize((1<<matchsticks.size())-1, 2);
        int mask = 0;
        return r(matchsticks, 0, mask);

    }
};