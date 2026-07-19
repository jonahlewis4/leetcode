class Solution {
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