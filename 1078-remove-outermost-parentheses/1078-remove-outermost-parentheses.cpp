class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        int open = 0;
        string cur = "";
        for(const auto & c : s) {
            cur += c;
            switch(c) {
                case '(':
                    open++;
                    break;
                case ')':
                    open--;
                    if(open == 0){
                        cur = cur.substr(1, cur.size() - 2);
                        res += cur;
                        cur = "";
                    
                    }
                    break;
            }
            
        }
        return res;
    }
};