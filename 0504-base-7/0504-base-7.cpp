class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0) {
            return "0";
        }
        string res = "";
        bool neg = false;
        if(num < 0) {
            neg = true;
            num = -num;
        }

        while(num > 0) {
            res += (char)(num % 7) + '0'; 
            num /= 7;
        }
        
        if(neg) {
            res += "-";
        }
        reverse(res.begin(), res.end());
        return res;
    }
};