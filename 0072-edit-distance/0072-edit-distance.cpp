class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.size() < word2.size()){
            swap(word1, word2);
        }

        vector<int> dp(word2.size() + 1, 0);
        for(int c = dp.size() - 1; c >= 0; c--){
            int ways = dp.size() - 1 - c;
            dp[c] = ways;
        }

        for(int r = word1.size() - 1; r >= 0; r--){
            int bottomRight = dp.back();
            dp.back() = dp.back() + 1;
            for(int c = word2.size() - 1; c >= 0; c--){
                int bottom = dp[c];
                int right = dp[c + 1];

                int res = INT_MAX;
                if(word1[r] == word2[c]){
                    res = min(res, bottomRight);
                }   

                res = min(res, right + 1);
                res = min(res, bottom + 1);
                res = min(res, bottomRight + 1);

                bottomRight = bottom;
                dp[c] = res;
            }
        }
        return dp.front();
    }
};