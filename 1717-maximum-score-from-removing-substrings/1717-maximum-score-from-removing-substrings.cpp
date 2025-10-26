class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int res = 0;

        stack<char> stk;

        const auto& maximal = [x, y](char c, char d) {
            if(x > y && c == 'b' && d == 'a'){
                return true;
            }
            if(y > x && c == 'a' && d == 'b'){
                return true;
            }

            return false;
        };

        for(const char c : s) {
            if(c != 'a' && c != 'b'){
                stk.push(c);
                continue;
            }
            if(!stk.empty() && stk.top() != c && maximal(c, stk.top())){
                stk.pop();
                res += max(x, y);
            } else {
                stk.push(c);
            }
        }

        if(!stk.empty()){
            char prev = stk.top();
            stk.pop();

            while(!stk.empty()){
                if(prev != stk.top() && (stk.top() == 'a' || stk.top() == 'b') && (prev == 'a' || prev == 'b')){
                    res += min(x, y);
                    stk.pop();
                    if(!stk.empty()){
                        char prev = stk.top();
                        stk.pop();
                    }
                } else {
                    prev = stk.top();
                    stk.pop();
                }
            }
        }

        return res;
    }
};