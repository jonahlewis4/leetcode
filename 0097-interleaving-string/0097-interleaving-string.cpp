class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
    
        if (s2.size() + s1.size() != s3.size()){
            return false;
        }

        if(s1.size() < s2.size()){
            swap(s1, s2);
        }    


        vector<bool> dp(s2.size() + 1, false);
        dp.back() = true;

        for(int c = dp.size() - 1; c >= 0; c--){
            if(s3[s1.size() + c] == s2[c] && dp[c + 1]){
                dp[c] = true;
            }
        }

        for(int r = s1.size() - 1; r>=0; r--){
            dp.back() = s3[s2.size() + r] == s1[r] && dp.back();
            for(int c = s2.size() - 1; c>=0; c--){
                bool res = false;
                bool right = dp[c + 1];
                bool below = dp[c];

                if(s3[r + c] == s1[r] && below) {
                    res = true;
                } else if (s3[r + c] == s2[c] && right) {
                    res = true;
                }

                right = res;
                dp[c] = res;

            }
        }
        return dp.front();
    }
};