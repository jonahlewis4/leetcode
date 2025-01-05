class Solution {
public:
    int calculate(string s) {
        int total = 0;
        int currentNumber = 0;
        int sign = 1;
        std::stack<int> stk;

        for(const char c : s){
            if(isdigit(c)){
                currentNumber *= 10;
                currentNumber += c - '0';
            } else if(c == '+' || c == '-'){
                total += currentNumber * sign;
                currentNumber = 0;
                sign = c == '+' ? 1 : -1;
            } else if (c == '('){
                stk.push(total);
                stk.push(sign);
                total = 0;
                sign = 1;
            } else if (c == ')'){
                total += currentNumber * sign;
                sign = 1;
                currentNumber = 0;
                total *= stk.top();
                stk.pop();
                total += stk.top();
                stk.pop();
            }
        }
        total += currentNumber * sign;
        return total;
    }
};