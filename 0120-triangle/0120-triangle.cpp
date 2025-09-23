class Solution {
    unordered_map<int, unordered_map<int, int>> dp;
    vector<vector<int>> t;
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        t = triangle;
        return r(0, 0);
    }
    int r(int level, int i) {
        if(dp.find(level) != dp.end()){
            if(dp[level].find(i) != dp[level].end()) {
                return dp[level][i];
            }
        }
        int nextLevel = level + 1;
        int val = t[level][i];
        if(nextLevel >= t.size()) {
            return val;
        }

        int l = r(nextLevel, i);
        int rr = INT_MAX;
        if(i + 1 < t[nextLevel].size()) {
            rr = r(nextLevel, i + 1);
        }
        
        int res = val + min(l, rr);
        dp[level][i] = res;
        return res;

    }
};