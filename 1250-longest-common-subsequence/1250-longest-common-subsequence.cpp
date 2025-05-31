class Solution {

    class Recursive{
        const string& text1;
        const string& text2;
    public:
        Recursive(const string& text1, const string& text2) : text1(text1), text2(text2) {

        }

        int Solution(){
            return recurse(0, 0);
        }
        int recurse(int i1, int i2){
            if(i1 >= text1.size() || i2 >= text2.size()){
                return 0;
            }

            if(text1[i1] == text2[i2]){
                int use = 1 + recurse(i1 + 1, i2 + 1);
                return use;
            }

            int skip1 = recurse(i1 + 1, i2);
            int skip2 = recurse(i1, i2 + 1);
            return max({skip1, skip2});
        }
    };

    class Memo {
        const string& text1;
        const string& text2;

        vector<vector<int>> dp;
    public:
        Memo(const string& text1, const string& text2) : text1(text1), text2(text2) {
            dp.resize(text1.size(), vector<int>(text2.size(), -1));
        }

        int Solution() {
            return recurse(0, 0);
        }

        int recurse(int i1, int i2) {
            if(i1 >= text1.size() || i2 >= text2.size()){
                return 0;
            }

            if(dp[i1][i2] != -1){
                return dp[i1][i2];
            }



            if(text1[i1] == text2[i2]){
                int use = 1 + recurse(i1 + 1, i2 + 1);
                dp[i1][i2] = use;
                return use;
            }

            int skip1 = recurse(i1 + 1, i2);
            int skip2 = recurse(i1, i2 + 1);
            dp[i1][i2] = max({skip1, skip2});
            return max({skip1, skip2});
        }
    };

    class Tabulation{
        const string& text1;
        const string& text2;

        vector<int> dp;
    public:
        Tabulation(const string& text1, const string& text2) : text1(text1), text2(text2) {
            dp.resize(text2.size() + 1, 0);
        }

        int Solution() {
            for(int r = text1.size() - 1; r >= 0; r--){
                int right = 0;
                int bottomRight = 0;
                for(int c = text2.size() - 1; c >= 0; c--) {
                    int bottom = dp[c];
                    if(text1[r] == text2[c]){
                        dp[c] = bottomRight + 1;
                        bottomRight = bottom;
                        right = dp[c];
                        continue;
                    }
                    
                    bottomRight = bottom;
                    dp[c] = max(right, bottom);

                }
            }

            return dp[0];
        }
    };

public:
    int longestCommonSubsequence(string text1, string text2) {
        return Tabulation(text1, text2).Solution();
    }
};