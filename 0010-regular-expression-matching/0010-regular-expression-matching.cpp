class Solution {
    string _s;
    string _p;
    bool starAfter(int pI) const {
        if(pI + 1 >= _p.size()) {
            return false;
        }
        return _p[pI + 1] == '*';
    }

    bool match(int pI, int sI) const {
        return _s[sI] == _p[pI] || _p[pI] == '.';
    }
public:
    bool isMatch(string s, string p) {
        _s = s;
        _p = p;

        vector<int> dp(p.size() + 1);
        dp.back() = true;
        for(int pI = p.size() - 2; pI >= 0; pI--){
            dp[pI] = starAfter(pI) && dp[pI + 2];
        }

        for(int sI = s.size() - 1; sI >= 0; sI--) {
            bool bottomRight = dp.back();
            dp.back() = false;
            for(int pI = p.size() - 1; pI >= 0; pI--) {
                bool res = false;
                if(starAfter(pI)) {
                    if(match(pI, sI)){
                        res |= dp[pI];
                    }
                    res |= dp[pI + 2];
                } else if(match(pI, sI)) {
                    res |= bottomRight;
                }

                bottomRight = dp[pI];
                dp[pI] = res;
            }
        }

        return dp.front();
    }
};