class Solution {
public:
    int numDistinct(string s, string t) {
        if(t.size() > s.size()){
            return 0;
        }

        vector<unsigned int> dp(t.size(), 0);
        int cc = t.size();
        int rc = s.size();

        for(int r = rc - 1; r >= 0; r--){
            unsigned int c = cc - 1;
            unsigned int bottomRight = 1;
            for(int i = 0; i < min(cc, rc - r); i++){
                int bottom = dp[c];

                unsigned int ways = bottom;
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