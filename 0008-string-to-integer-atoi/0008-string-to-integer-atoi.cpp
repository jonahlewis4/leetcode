class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        while(i < s.size() && s[i] == ' '){
            i++;
        }
        if(i >= s.size()){
            return 0;
        }
        bool negative = s[i] == '-';
        if(negative || s[i] == '+'){
            i++;
        }
        int sum = 0;
        while(i < s.size() && isdigit(s[i])){
            int digit = int(s[i] - '0');
            if(sum > INT_MAX / 10 || sum == INT_MAX / 10 && digit > INT_MAX % 10){
                if(negative){
                    return INT_MIN;
                } else {
                    return INT_MAX;
                }

            }
            sum *= 10;
        
            sum += digit;
            i++;
        }

        if(negative){
            sum *= -1;
        }
        return sum;
    }
};