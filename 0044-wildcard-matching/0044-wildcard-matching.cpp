class Solution {
    // bool r(int sI, int pI) {
    //     if(dp[sI][pI] != -1) {
    //         //cout<<"cached value found"<<endl;
    //         return dp[sI][pI];
    //     }
    //     if(sI >= s.size()) {
    //         if(pI >= p.size()) {
    //             //cout<<"end of pattern and input, return true"<<endl;
    //             dp[sI][pI] = true;
    //             return true;
    //         }
    //         if(p[pI] == '*'){
    //             //cout<<"end of input but asteriks found"<<endl;
    //             dp[sI][pI] = r(sI, pI+1);
    //             return dp[sI][pI];
    //         }

    //         //cout<<"end of input, but pattern wasn't finished, return false"<<endl;
    //         dp[sI][pI] = false;
    //         return dp[sI][pI];
    //     }

    //     if(pI >= p.size()) {
    //         //cout<<"end of pattern but not end of input, return false"<<endl;
    //         dp[sI][pI] = false;
    //         return dp[sI][pI];
    //     }

    //     char pVal = p[pI];
    //     //cout<<pVal<<endl;
    //     if(pVal == '?') {
    //         //cout<<"qMark, skipping"<<endl;
    //         dp[sI][pI] = r(sI+1, pI+1);
    //         return dp[sI][pI];
    //     } else if (pVal == '*') {
    //         bool attempt1 = r(sI+1, pI);
    //         bool attempt2 = r(sI, pI+1);
    
    //         dp[sI][pI] = attempt1 || attempt2;
    //         return dp[sI][pI];
    //     } else {
    //         if (pVal != s[sI]){
    //             //cout<<"no match"<<endl;
    //             dp[sI][pI] = false;
    //             return dp[sI][pI];
    //         }
    //         //cout<<"match"<<endl;
    //         dp[sI][pI] = r(sI+1, pI+1);
    //         return dp[sI][pI];
    //     }
    // }
public:
    bool isMatch(string s, string p) {
        vector<bool> dp(p.size());
        if(p.empty()) {
            return s.empty();
        }
        bool right = true;
        for(int i = p.size() - 1; i >= 0; i--) {
            dp[i] = p[i] == '*' && right;
            right = dp[i];
        }

        bool botRight = true;
        for(int sI = s.size() - 1; sI >= 0; sI--){
            right = false;
            
            for(int pI = p.size() - 1; pI >= 0; pI--) {
                bool old = dp[pI];
                char pVal = p[pI];
                if(pVal == '?') {
                    dp[pI] = botRight;
                } else if (pVal == '*'){
                    bool attempt1 = dp[pI];
                    bool attempt2 = right;

                    dp[pI] = attempt1 || attempt2;
                } else {
                    if(pVal != s[sI]) {
                        dp[pI] = false;
                    } else {
                        dp[pI] = botRight;
                    }
                }
                
                botRight = old;
                right = dp[pI];
            
            }
            botRight = false;
        }

        return dp.front();
        
        
        
    }
};