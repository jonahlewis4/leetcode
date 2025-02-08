class Solution {
public:
    int longestValidParentheses(string s) {
        int maxans = 0;
        vector<int> dp(s.length());
        for (int i = 1; i < s.length(); i++) {
            if(s[i] == ')' && s[i - 1] == '('){
                int preceeding = i - 2 >= 0 ? dp[i - 2] : 0;
                dp[i] = preceeding + 2;
            } else if(s[i] == ')' && s[i - 1] == ')'){
                int openPreceedingIdx = i - dp[i - 1] - 1;
                int possibleAdditionVal = openPreceedingIdx - 1 >= 0 ? dp[openPreceedingIdx - 1] : 0;
                int preceedingVal = dp[i - 1];
                if(openPreceedingIdx >= 0 && s[openPreceedingIdx] == '('){
                    dp[i] = possibleAdditionVal + preceedingVal;
                    dp[i] += 2;
                }
            }
            maxans = max(maxans, dp[i]);
        }

        return maxans;
    }
};