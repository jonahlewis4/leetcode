class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        int open = 0;
        for(const auto & c : s) {
            switch(c) {
                case '(':
                    if(open != 0){
                        res += c;
                    }
                    open++;
                    break;
                case ')':
                    open--;
                    if(open != 0){
                        res += c;
                    }
                    break;
            }
            
        }
        return res;
    }
};