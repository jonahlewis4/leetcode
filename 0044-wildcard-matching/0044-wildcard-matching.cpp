class Solution {
    string s;
    string p;
    vector<vector<int>> dp;
    bool r(int sI, int pI) {
        if(dp[sI][pI] != -1) {
            //cout<<"cached value found"<<endl;
            return dp[sI][pI];
        }
        if(sI >= s.size()) {
            if(pI >= p.size()) {
                //cout<<"end of pattern and input, return true"<<endl;
                dp[sI][pI] = true;
                return true;
            }
            if(p[pI] == '*'){
                //cout<<"end of input but asteriks found"<<endl;
                dp[sI][pI] = r(sI, pI+1);
                return dp[sI][pI];
            }

            //cout<<"end of input, but pattern wasn't finished, return false"<<endl;
            dp[sI][pI] = false;
            return dp[sI][pI];
        }

        if(pI >= p.size()) {
            //cout<<"end of pattern but not end of input, return false"<<endl;
            dp[sI][pI] = false;
            return dp[sI][pI];
        }

        char pVal = p[pI];
        //cout<<pVal<<endl;
        if(pVal == '?') {
            //cout<<"qMark, skipping"<<endl;
            dp[sI][pI] = r(sI+1, pI+1);
            return dp[sI][pI];
        } else if (pVal == '*') {
            bool attempt1 = r(sI+1, pI);
            bool attempt2 = r(sI, pI+1);
    
            dp[sI][pI] = attempt1 || attempt2;
            return dp[sI][pI];
        } else {
            if (pVal != s[sI]){
                //cout<<"no match"<<endl;
                dp[sI][pI] = false;
                return dp[sI][pI];
            }
            //cout<<"match"<<endl;
            dp[sI][pI] = r(sI+1, pI+1);
            return dp[sI][pI];
        }
    }
public:
    bool isMatch(string s, string p) {
        dp.resize(s.size() + 1, vector<int>(p.size() + 1, -1));
        this->s = s;
        this->p = p;

        return r(0, 0);
    }
};