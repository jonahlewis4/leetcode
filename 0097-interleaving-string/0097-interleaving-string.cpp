class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) {
            return false;
        }

        if(s1.size() > s2.size()) {
            swap(s1, s2);
        }

        vector<bool> dp(s1.size() + 1);
        dp.back() = true;
        for(int i = dp.size() - 2; i >= 0; i--) {
            dp[i] = dp[i + 1] && s1[i] == s3[s2.size() + i];
        }

        for(int i2 = s2.size(); i2 >= 0; i2--) {
            dp.back() = s2[i2] == s3[i2 + s1.size()] && dp.back();
            for(int i1 = s1.size(); i1 >= 0; i1--) {
                bool res = false;
                char target = s3[i1 + i2];
                if(s1[i1] == target){
                    res |= dp[i1 + 1];
                }

                if(s2[i2] == target) {
                    res |= dp[i1];
                }

                dp[i1] = res;
            }
        }

        return dp.front();
    }
};