class Solution {
public:
    int calculate(string s) {
        
        //(1 + (4 + 5 + 2) - 3) - (6 - (-4))
        //9
        //- 10


        stack<int> stk;
        int sign = 1;
        int total = 0;
        int curVal = 0;
        stk.push(0);
        for(const auto & c : s) {
            switch (c) {
                case ' ':{
                    break;
                }
                case '(': {
                    stk.push(total);
                    stk.push(sign);
                    sign = 1;
                    total = 0;
                    break;
                }
                    
                case ')': {
                    total += curVal;
                    curVal = 0;
                    int localSign = stk.top();
                    stk.pop();
                    total = stk.top() + total * localSign;
                    stk.pop();
                    break;
                }
                
                case '+': {
                    total += curVal;
                    curVal = 0;
                    sign = 1;
                    break;
                }
                    
                case '-': {
                    total += curVal;
                    curVal = 0;
                    sign = -1;
                    break;  
                }
                    
                default: {
                    int val = c - '0';
                    curVal *= 10;
                    curVal += val * sign;
                }
            }
        }
        total += curVal;
        return total;
    }
};