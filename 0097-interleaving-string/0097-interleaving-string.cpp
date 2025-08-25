class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) {
            return false;
        }
        if(s1.size() > s2.size()) {
            swap(s1, s2);
        }
        if(s1.size() == 0) {
            return s2 == s3;
        }
        //s1 is the samller of the two.

        vector<bool> dp(s1.size() + 1, 0);
        dp.back() = true;
        for(int i = s1.size() - 1; i >= 0; i--) {
            if(s1[i] == s3[s2.size() + i]){
                dp[i] = dp[i] | dp[i + 1];
            }
        }

        for(int j = s2.size() - 1; j >= 0; j--) {
            dp.back() = (s3[s1.size() + j] == s2[j]) && dp.back();
            for(int i = s1.size() - 1; i >= 0; i--) {
                char interC = s3[i + j];
                bool res = false;
                if(interC == s2[j]) {
                    res |= dp[i];
                }
                if(interC == s1[i]) {
                    res |= dp[i + 1];
                }
                dp[i] = res;
            }
        }
        return dp.front();
    }
};