class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if(text1.size() < text2.size()){
            swap(text1, text2);
        }

        vector<int> dp(text2.size() + 1, 0);
        for(int r = text1.size() - 1; r >= 0; r--){
            int bottomRight = 0;
            for(int c = text2.size() - 1; c >= 0; c--){
                int bottom = dp[c];
                int right = dp[c + 1];

                int best = 0;
                if(text1[r] == text2[c]){
                    best = max(best, 1 + bottomRight);
                }
                best = max(best, right);
                best = max(best, bottom);
                bottomRight = bottom;
                dp[c] = best;
            }
        }
        return dp[0];
    }
};