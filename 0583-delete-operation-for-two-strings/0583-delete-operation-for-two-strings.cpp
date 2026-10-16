class Solution {
    string word1;
    string word2;

    int r(int i1, int i2) {
        if(i1 >= word1.size()) {
            return word2.size() - i2;
        }
        if(i2 >= word2.size()) {
            return word1.size() - i1;
        }

        if(dp[i1][i2] != -1) {
            return dp[i1][i2];
        }

        int res;
        if(word1[i1] == word2[i2]) {
            res = r(i1+1, i2+1);
        } else {
            int skip1 = r(i1 + 1, i2);
            int skip2 = r(i1, i2 + 1);
            res = 1 + min(skip1, skip2);
        }
        dp[i1][i2] = res;
        return res;
    }
    vector<vector<int>> dp;
public:
    int minDistance(string word1, string word2) {
        this->word1 = word1;
        this->word2 = word2;
        dp.resize(word1.size(), vector<int> (word2.size(), -1));
        return r(0, 0);    
    }
};