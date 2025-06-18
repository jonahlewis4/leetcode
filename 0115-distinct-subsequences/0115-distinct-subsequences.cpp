class Solution {
private:
    class Recursive {
    private:
        const string& s;
        const string& t;
    public:
        Recursive(const string& s, const string& t) : s(s), t(t) {}
        
        int Solve() const {
            return calc(0, 0);
        }
        
        int calc(int i, int j) const {
            if(j >= t.size()){
                return 1;
            }
            if(i >= s.size()){
                return 0;
            }

            if(s[i] == t[j]) {
                int use = calc(i + 1, j + 1);
                int skip = calc(i + 1, j);
                return use + skip;
            }

            return calc(i + 1, j);
        }
    };
    class Tabulation {
        private:
        const string& s;
        const string& t;
    public:
        Tabulation(const string& s, const string& t) : s(s), t(t) {}
        int Solve() {
            vector<unsigned int> dp(t.size() + 1);
            dp.back() = 1;
            for(int i = s.size() - 1; i >= 0; i--) {
                int bottomRight = dp.back();
                for(int j = t.size() - 1; j >= 0; j--) {
                    int bottom = dp[j];
                    unsigned int res = bottom;
                    if(s[i] == t[j]){
                        res = min(res + bottomRight, (unsigned int)INT_MAX);
                    }
                    bottomRight = bottom;
                    dp[j] = res;
                }
            }
            return dp[0];
        }
    };
public:
    int numDistinct(string s, string t) {
        if(t.size() > s.size()) {
            return 0;
        }
        return Tabulation(s, t).Solve();
        
    }
};