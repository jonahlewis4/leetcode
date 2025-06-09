class Solution {
    string s;
    string p;

    vector<vector<int>> dp;
    bool starAfter(int pI) const {
        if(pI + 1 >= p.size()){
            return false;
        }
        if(p[pI + 1] == '*'){
            return true;
        }
        return false;
    }
    bool match(int sI, int pI) const {
        return s[sI] == p[pI] || p[pI] == '.';
    }
public:
    bool isMatch(string s, string p) {
        this->s = s;
        this->p = p;
        vector<bool> dp(p.size() + 1, false);
        //need to track below, right two, bottom right
        dp.back() = true;

        for(int c = dp.size() - 2; c >= 0; c--){
            if(p[c] == '*'){
                continue;
            }

            if(starAfter(c)){
                dp[c] = dp[c + 2];
            }
        }

        for(int r = s.size() - 1; r >= 0; r--) {
            int botRight = dp.back();
            dp.back() = false;
            int twoRight = false;
            int right = dp.back();

            

            for(int c = p.size() - 1; c >= 0; c--) {
                int below = dp[c];

                const auto & update = [&botRight, &twoRight, &right, &dp, &below, &c](int res) {
                    twoRight = right;
                    botRight = below;
                    right = res;
                    dp[c] = res;
                };

                if(p[c] == '*'){
                    update(false);
                    continue;
                }


                if(starAfter(c)) {
                    bool res = false;
                    if(match(r, c)){
                        res |= below;
                    }
                    res |= twoRight;

                    update(res);
                    continue;
                } else {
                    if (match(r, c)) {
                        bool res = botRight;
                        update(res);
                    } else {
                        update(false);
                    }
                }
            }

        }


        return dp[0];

    }
};