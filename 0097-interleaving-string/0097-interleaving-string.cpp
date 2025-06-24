class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()){
            return false;
        }
        if(s1.size() < s2.size()){
            swap(s1, s2);
        }

        //if 1 match 
            //i + 1, j
        //if 2 match
            //i, j + 1
        
        vector<bool> dp(s2.size() + 1, false);
        dp.back() = true;

        for(int c = dp.size() - 2; c >= 0; c--){
            dp[c] = s2[c] == s3[s1.size() + c] && dp[c + 1];
        }

        for(int r = s1.size() - 1; r >= 0; r--) {
            dp.back() = dp.back() && s3[s2.size() + r] == s1[r];
            for(int c = s2.size() - 1; c >= 0; c--){
                int below = dp[c];
                int right = dp[c + 1];
                
                int res = false;
                res |= s1[r] == s3[r + c] && below;
                res |= s2[c] == s3[r + c] && right;
                dp[c] = res;
            }
        }
        return dp.front();
    }
};