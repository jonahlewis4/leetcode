class Solution {
    string _s;
    string _p;
    bool starAfter(int pI) const {
        if(pI + 1 >= _p.size()) {
            return false;
        }
        return _p[pI + 1] == '*';
    }
    bool match(int sI, int pI) const {
        return _s[sI] == _p[pI] || _p[pI] == '.';
    }
public:
    bool isMatch(string s, string p) {
        _s = s;
        _p = p;

        vector<bool> dp(p.size() + 1, false);
        dp.back() = true;

        for(int pI = _p.size() - 2; pI >= 0; pI--) {
            if(starAfter(pI)){
                dp[pI] = dp[pI + 2];
            }
        }
        for(int sI = s.size() - 1; sI >= 0; sI--) {
            bool bottomRight = dp.back();
            dp.back() = false;
            for(int pI = _p.size() - 1; pI >= 0; pI--) {
                bool res = false;
                if(starAfter(pI)){
                    if(match(sI, pI)) {
                        res |= dp[pI];
                    }
                    res |= dp[pI + 2];
                } else if (match(sI, pI)) {
                    res |= bottomRight;
                }   
                
                bottomRight = dp[pI];
                dp[pI] = res;
            }
        }

        return dp.front();
    }
};