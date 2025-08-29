class Solution {
public:
    int calculate(string s) {
        int total = 0;
        int sign = 1;
        int curNum = 0;
        stack<int> stack;
        for(const char c : s) {
            switch (c) {
                case '+': {
                    total += curNum * sign;
                    sign = 1;
                    curNum = 0;
                    break;
                }
                case '-': {
                    total += curNum * sign;
                    sign = -1;
                    curNum = 0;
                    break;
                }
                case '(': {
                    stack.push(total);
                    stack.push(sign);
                    total = 0;
                    sign = 1;
                    break;
                }
                case ')': {
                    total += curNum * sign;
                    curNum = 0;
                    char localSign = stack.top();
                    stack.pop();
                    total = stack.top() + total * localSign;
                    stack.pop();
                    break;
                }
                case ' ': {
                    break;
                }
                default: {
                    curNum *= 10;
                    curNum += c - '0';
                }

            }
        }
        total += curNum * sign;
        return total;
    }
};