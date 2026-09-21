class Solution {
    // int calc(int l, int r, const string& s) {
    //     if(l > r) {
    //         return 0;
    //     }
    //     if(l == r) {
    //         return 1;
    //     }

    //     if(cache[l][r] != -1) {
    //         return cache[l][r];
    //     }
    //     if(s[l] == s[r]) {
    //         int res = 2 + calc(l+1, r-1, s);
    //         cache[l][r] = res;
    //         return res;
    //     }
    //     int optL = calc(l+1, r, s);
    //     int optR = calc(l, r-1, s);
        
    //     int res = max(optL, optR);
    //     cache[l][r] = res;
    //     return res;
    // }
    
public:
    int longestPalindromeSubseq(string s) {
        vector<int> dp(s.size(), 0);
        for(int l = s.size() - 1; l >= 0; l--) {
            int botLeft = 0;
            dp[l] = 1;
            for(int r = l + 1; r < s.size(); r++) {
                int res;
                if(s[l] == s[r]) {
                    res = 2 + botLeft;
                } else {
                    int optL = dp[r-1];
                    int optB = dp[r];
                    res = max(optL, optB);
                }
                botLeft = dp[r];
                dp[r] = res;
            }
        }

        return dp.back();
    }
};