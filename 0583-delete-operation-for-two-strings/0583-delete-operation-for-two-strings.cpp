class Solution {
   
public:
    int minDistance(const string& word1, const string& word2) {
        
        vector<int> dp(word1.size(), 0);
        for(int i = 0; i < word1.size(); i++) {
            dp[i] = word1.size() - i;
        }
        for(int i2 = word2.size() - 1; i2 >= 0; i2--) {
            int bottomRight = word2.size() - i2 - 1;
            int right = bottomRight + 1;
            for(int i1 = word1.size() - 1; i1 >= 0; i1--) {
                int bottom = dp[i1];
                int res;

                if(word1[i1] == word2[i2]) {
                    res = bottomRight;
                } else {
                    res = 1 + min(
                        right,
                        bottom
                    );
                }


                bottomRight = bottom;
                right = res;
                dp[i1] = res;
            }
        }

        return dp.front();
    }
};