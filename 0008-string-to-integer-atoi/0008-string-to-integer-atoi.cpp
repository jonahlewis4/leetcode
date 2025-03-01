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
        long long sum = 0;
        while(i < s.size() && isdigit(s[i])){
            sum *= 10;
            if(negative){
                sum -= int(s[i] - '0');
            } else {
                sum += int(s[i] - '0');
            }
            sum = max((long long)INT_MIN, sum);
            sum = min((long long)INT_MAX, sum);
            i++;
        }

        return sum;
    }
};