class Solution {
    string s;
    string p;

    vector<vector<int>> dp;
    bool starAfter(int pI) const {
        if(pI + 1 < p.size() && p[pI + 1] == '*'){
            return true;
        }
        return false;
    }
    bool match(int sI, int pI) const {
        return s[sI] == p[pI] || p[pI] == '.';
    }
    bool calc(int sI, int pI) {

        if(sI == s.size() && pI == p.size()){
            return true;
        }

        if(sI > s.size()){
            return false;
        }

        if(pI >= p.size()){
            return false;
        }

        if(dp[sI][pI] != -1){
            return dp[sI][pI];
        }


        if(starAfter(pI)){
            bool res = false;
            if(match(sI, pI)){
                res |= calc(sI + 1, pI);
            }
            res |= calc(sI, pI + 2);
            dp[sI][pI] = res;
            return res;
        } else {
            if(match(sI, pI)){
                int res = calc(sI + 1, pI + 1);
                dp[sI][pI] = res;
                return res;
            }
        }
        dp[sI][pI] = false;
        return false;
    }
public:
    bool isMatch(string s, string p) {
        dp.resize(s.size() + 1, vector<int>(p.size(), -1));
        this->s = s;
        this->p = p;
        return calc(0, 0);
    }
};