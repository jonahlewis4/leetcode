class Solution {
private:
    static tuple<int, int> calculate(const string& s, int i) {
        int total = 0;
        int curVal = 0;
        int sign = 1;
        while(i < s.size()) {
            char c = s[i];
            switch (c) {
                case ' ':{
                    break;
                }
                case '(': {
                    const auto [localVal, end] = calculate(s, i + 1);
                    total += sign * localVal;
                    i = end; 
                    break;
                }
                    
                case ')': {
                    total += curVal;
                    return {total, i};
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
            i++;
        }
        total += curVal;
        return {total, s.size()};
    }
public:
    int calculate(string s) {
        const auto [total, _] = calculate(s, 0);
        return total;
    }
};