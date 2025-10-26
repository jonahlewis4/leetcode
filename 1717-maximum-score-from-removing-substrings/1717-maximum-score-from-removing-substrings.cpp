class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int res = 0;

        stack<char> stk;

        for(const char c : s){
            if(stk.empty() || c != 'a' && c != 'b' || stk.top() == c || (stk.top() != 'a' && stk.top() != 'b')){
                stk.push(c);
                continue;
            }

            if((x >= y && c == 'b') || (y > x && c == 'a')){
                res += max(x, y);
                stk.pop();
                continue;
            }

            stk.push(c);
        }
        
        char desiredRight = x >= y ? 'a' : 'b';
        char desiredLeft = x >= y ? 'b' : 'a';

        stack<char> stk2;
        while(!stk.empty()) {
            if(stk2.empty()){
                stk2.push(stk.top());
                stk.pop();
                continue;
            }

            if(stk.top() == desiredLeft && stk2.top() == desiredRight) {
                res += min(x, y);
                stk.pop();
                stk2.pop();
                continue;
            }

            stk2.push(stk.top());
            stk.pop();
        }

        return res;
    }
};