class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open = 0;
        string rightFix = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] != '(' && s[i] != ')'){
                rightFix += s[i];
            } else if(s[i] == '('){
                rightFix += s[i];
                open++;
            } else {
                if(open > 0){
                    rightFix += s[i];
                    open--;
                }
            }
        }

        int close = 0;
        string res = "";
        for(int i = rightFix.size() - 1; i >= 0; i--){
            if(rightFix[i] != '(' && rightFix[i] != ')'){
                res += rightFix[i];
            } else if(rightFix[i] == ')'){
                res += rightFix[i];
                close++;
            } else {
                if(close > 0){
                    res += rightFix[i];
                    close--;
                }
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};