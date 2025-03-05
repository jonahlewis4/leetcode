class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int i = 0;
        skipWhite(i, s);
        int num = getNum(i, s);
        stk.push(num);
        while(i < s.size()){
            char op = getOp(i, s);
            int num = getNum(i ,s);
            if(op == '-' ){
                stk.push(-num);
            } else if (op == '+'){
                stk.push(num);
            } else if(op == '*'){
                int top = stk.top();
                stk.pop();
                stk.push(top * num);
            } else {
                int top = stk.top();
                stk.pop();
                stk.push(top / num);
            }
        }
        int sum = 0;
        while(!stk.empty()){
            sum += stk.top();
            stk.pop();
        }
        return sum;
    }
    void skipWhite(int &i, const string& s){
        while(i < s.size() && s[i] == ' '){
            i++;
        }
    }
    char getOp(int &i, const string& s){
        char op = s[i];
        i++;
        skipWhite(i, s);
        return op;
    }
    int getNum(int &i, const string&s){
        int num = 0;
        while(i < s.size() && isdigit(s[i])){
            num *= 10;
            num += s[i] - '0';
            i++;
        }
        skipWhite(i, s);
        return num;

    }
};