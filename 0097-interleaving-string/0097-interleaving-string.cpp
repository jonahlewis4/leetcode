class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()){
            return false;
        }

        if(s1.size() < s2.size()){
            swap(s1, s2);
        }

        //s1 is row;
        //s2 is col;
        //col is the smaller of the two. Space has been minimized.

        if(s2.size() == 0){
            return s1 == s3;
        }

        vector<bool> dp(s2.size() + 1, false);
        dp.back() = true;

        for(int r = s1.size(); r >= 0; r--){
            int right = 0;
            for(int c = s2.size(); c >= 0; c--){
                //k is the index in string3
                int k = r + c;
                if(k >= s3.size()){
                    right = dp[c];
                    continue;
                }

                int below = dp[c];

                bool cMatch = s2[c] == s3[k];
                bool rMatch = r < s1.size() && s1[r] == s3[k];

                if(cMatch && right) {
                    dp[c] = true;
                } else if (rMatch && below) {
                    dp[c] = true;
                } else {
                    dp[c] = false;
                }
                right = dp[c];
            }
        }

        return dp[0];
    }
};