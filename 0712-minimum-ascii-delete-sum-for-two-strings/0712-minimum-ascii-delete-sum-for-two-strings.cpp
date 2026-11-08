class Solution {
    int r(int i, int j, const string& s1, const string& s2) {
        if(i >= s1.size() && j >= s2.size()) {
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(i >= s1.size()) {
            int res = s2[j] + r(i, j + 1, s1, s2);
            dp[i][j] = res;
            return res;
        }
        if(j >= s2.size()) {
            int res = s1[i] + r(i + 1, j, s1, s2);
            dp[i][j] = res;
            return res;
        }

        if(s1[i] == s2[j]) {
             int res = r(i + 1, j + 1, s1, s2);
             dp[i][j] = res;
            return res;
        }
        int l = s1[i] + r(i + 1, j, s1, s2);
        int right = s2[j] + r(i, j + 1, s1, s2);

        int res = min(l, right);
        dp[i][j] = res;
        return res;
    }
public:
    vector<vector<int>> dp;
    int minimumDeleteSum(string s1, string s2) {
        dp.resize(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return r(0, 0, s1, s2);
    }
};