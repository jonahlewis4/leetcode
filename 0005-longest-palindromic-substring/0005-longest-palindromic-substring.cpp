class Solution {
public:
    string longestPalindrome(const string &s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        string longest = "";
        for(int k = 0; k < dp.size(); k++){
            for(int l = 0; l < dp.size() - k; l++){
                int r = l + k;
                int substringLength = r - l + 1;
                if(substringLength == 1){
                    dp[l][r] = true;
                } else if(substringLength == 2){
                    dp[l][r] = s[l] == s[r];
                } else {
                    dp[l][r] = dp[l + 1][r - 1] && s[l] == s[r];
                }

                if (dp[l][r] && substringLength > longest.size()){
                    longest = s.substr(l, substringLength);
                }

            }
        }
        return longest;


    }
};