class Solution {
    class Parser{
        const string& s;
        const string& p;
        public:
        Parser(const string& s, const string& p): s(s), p(p) {}
        bool starAfter(int pI) const {
            if(pI + 1 < p.size() && p[pI + 1] == '*') {
                return true;
            }
            return false;
        }
        bool match(int sI, int pI) const {
            if(p[pI] == '.' || s[sI] == p[pI]){
                return true;
            }
            return false;
        }
    };

    class Memo{
    const string& s;
    const string& p;
    Parser parser;
    vector<vector<int>> dp;
    public:
        Memo(const string& s, const string& p): s(s), p(p), parser(Parser(s, p)),
            dp(vector<vector<int>>(s.size() + 1, vector<int>(p.size(), -1)))
        {
            
        }
        bool solve()  {
            return recurse(0, 0);
        }
        bool recurse(int sI, int pI)  {
            if(sI >= s.size() && pI >= p.size()) {
                return true;
            }
            if(pI >= p.size()) {
                return false;
            }

            //memoize
            if(dp[sI][pI] != -1){
                return dp[sI][pI];
            }

            if(sI >= s.size()){
                if(parser.starAfter(pI)){
                    bool skip = recurse(sI, pI + 2);
                    dp[sI][pI] = skip;
                    return skip;
                }
                dp[sI][pI] = false;
                return false;
            }

            if(parser.starAfter(pI)) {
                bool res = false;
                if(parser.match(sI, pI)) {
                    bool use = recurse(sI + 1, pI);
                    res |= use;
                }
                bool skip = recurse(sI, pI + 2);
                res |= skip;
                dp[sI][pI] = res;
                return res;
            } else if (parser.match(sI, pI)) {
                bool use = recurse(sI + 1, pI + 1);
                dp[sI][pI] = use;
                return use;
            }

            dp[sI][pI] = false;
            return false;
        }
    } ;

    class Tabulation {
        const string& s;
        const string& p;
        Parser parser;
        vector<bool> dp;
        public:
        Tabulation(const string& s, const string& p): s(s), p(p), parser(Parser(s, p)),
            dp(p.size() + 2, false)
        {
            dp[dp.size() - 2] = true;
            for(int i = dp.size() - 4; i >= 0; i--){
                if(!parser.starAfter(i)) {
                    dp[i] = false;
                } else {
                    bool skip = dp[i + 2];
                    dp[i] = skip;
                }
            }
        }

        bool solve() {
            const auto & _dp = dp;
            for(int r = s.size() - 1; r >= 0; r--){
                bool bottomRight = dp[dp.size() - 2];
                dp[dp.size() - 2] = false;
                for(int c = p.size() - 1; c >= 0; c--){
                    int below = dp[c];
                    int right2 = dp[c + 2];

                    if(parser.starAfter(c)){
                        bool res = false;
                        bool skip = right2;
                        res |= skip;
                        if(parser.match(r,c)){
                            bool use = below;
                            res |= use;
                        }
                        dp[c] = res;
                    } else if (parser.match(r,c)){
                        bool use = bottomRight;
                        dp[c] = use;
                    } else {
                        dp[c] = false;
                    }




                    bottomRight = below;
                }
            }



            return dp.front();
        }
    };
public:
    bool isMatch(string s, string p) {
        return Tabulation(s, p).solve();
    }
};