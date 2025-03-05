class Solution {
public:
    int calculate(string s) {
        int i = 0;
        skipWhite(i, s);
        int num = getNum(i, s);
        int sum = 0;
        int prev = num;
        while(i < s.size()){
            char op = getOp(i, s);
            int num = getNum(i ,s);
            if(op == '-' ){
                sum += prev;
                prev = -num;
            } else if (op == '+'){
                sum += prev;
                prev = num;
            } else if(op == '*'){
                prev = prev * num;
            } else {
                prev = prev / num;
            }
        }
        sum += prev;
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