class Solution {
    class Regex{
    private:
        const string& s;
        const string& p;
    public:
        Regex(const string& s, const string& p) : s(s), p(p) {}
        bool match(int sI, int pI) const {
            if(p[pI] == '.' || s[sI] == p[pI]) {
                return true;
            }
            return false;
        }

        bool starAfter(int pI) const {
            if(pI + 1 < p.size() && p[pI + 1] == '*'){
                return true;
            }
            return false;
        }
    };
public:
    bool isMatch(string s, string p) {
        vector<bool> dp(p.size() + 1, false);
        dp.back() = true;
        
        Regex reg(s, p);
        //initialize final row
        //this represents if we've completed the s string.
        //if the s string is completed that means the only successful patterns
        //would be stars, which can be empty (ie ones that don't have s)

        for(int i = dp.size() - 3; i >= 0; i--) {
            dp[i] = reg.starAfter(i) && dp[i + 2];
        }

        for(int sI = s.size() - 1; sI >= 0; sI--) {
            bool bottomRight = dp.back();
            dp.back() = false;

            for(int pI = p.size() - 1; pI >= 0; pI--) {
                bool res = false;
                bool below = dp[pI];
                if(reg.starAfter(pI)) {
                    if(reg.match(sI, pI)){ 
                        res |= below;
                    }
                    res |= dp[pI + 2];
                } else if (reg.match(sI, pI)) {
                    res = bottomRight;
                } else {
                    res = false;
                }
                dp[pI] = res;
                bottomRight = below;
            }
        }
        return dp.front();
    }
};