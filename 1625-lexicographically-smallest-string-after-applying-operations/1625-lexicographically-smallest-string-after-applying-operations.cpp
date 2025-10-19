class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> enqueued;
        string best = s;

        stack<string> stk;
        stk.push(s);
        enqueued.insert(s);
        while(!stk.empty()){
            string curString = stk.top();
            stk.pop();

            best = min(best, curString);

            string op1 = operation1(curString, a);
            if(!enqueued.contains(op1)){
                enqueued.insert(op1);
                stk.push(op1);
            }

            string op2 = operation2(curString, b);
            if(!enqueued.contains(op2)){
                enqueued.insert(op2);
                stk.push(op2);
            }
        }

        return best;
    }

    string operation1(string s, int a) {
        for(int i = 1; i < s.size(); i += 2) {
            s[i] += a;
            if(s[i] > '9'){
                s[i] -= 10;
            }
        }
        return s;
    }
    string operation2(string s, int b) {
        string res(s.size(), '.');
        for(int i = 0; i < res.size(); i++) {
            if(i - b >= 0) {
                res[i] = s[i - b];
            } else {
                res[i] = s[i - b + s.size()];
            }
        }
        return res;
    }
};