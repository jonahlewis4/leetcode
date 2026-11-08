class Solution {
    // int r(int i, int j, const string& s1, const string& s2) {
    //     if(i >= s1.size() && j >= s2.size()) {
    //         return 0;
    //     }
    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }
    //     if(i >= s1.size()) {
    //         int res = s2[j] + r(i, j + 1, s1, s2);
    //         dp[i][j] = res;
    //         return res;
    //     }
    //     if(j >= s2.size()) {
    //         int res = s1[i] + r(i + 1, j, s1, s2);
    //         dp[i][j] = res;
    //         return res;
    //     }

    //     if(s1[i] == s2[j]) {
    //          int res = r(i + 1, j + 1, s1, s2);
    //          dp[i][j] = res;
    //         return res;
    //     }
    //     int l = s1[i] + r(i + 1, j, s1, s2);
    //     int right = s2[j] + r(i, j + 1, s1, s2);

    //     int res = min(l, right);
    //     dp[i][j] = res;
    //     return res;
    // }
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<int> dp(s2.size() + 1, 0);
        for(int i = s2.size() - 1; i >= 0; i--) {
            dp[i] = dp[i+1] + s2[i];
        }

        for(int r = s1.size() - 1; r >= 0; r--) {
            int bottomRight = dp.back();
            dp.back() = dp.back() + s1[r];
            for(int c = s2.size() - 1; c >= 0; c--) {
                int right = s2[c] + dp[c + 1];
                int below = s1[r] + dp[c];

                if(s1[r] == s2[c]){
                    dp[c] = bottomRight;
                } else {
                    dp[c] = min(right, below);
                }

                bottomRight = below - s1[r];
            }   
        }

        return dp.front();
    }
};