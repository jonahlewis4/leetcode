class Solution {
public:
    int numDistinct(string s, string t) {
        if(t.size() > s.size()){
            return 0;
        }

        vector<int> dp(t.size(), 0);
        int cc = t.size();
        int rc = s.size();

        for(int r = rc - 1; r >= 0; r--){
            int c = cc - 1;
            int bottomRight = 1;
            for(int i = 0; i < cc; i++){
                int bottom = dp[c];

                long long ways = bottom;
                if(s[r] == t[c]){
                    ways += bottomRight;
                }

                bottomRight = bottom;
                dp[c] = ways > INT_MAX ? -1 : ways;
                c--;
            }
        }
        return dp[0];
    }
};