class Solution {
public:
    string toHex(int numIn) {
        if(numIn == 0) {
            return "0";
        }
        unsigned int num;
        if(numIn < 0) {
            num = (~0u) + numIn + 1;
        } else {
            num = numIn;
        }

        string res = "";
        while(num > 0) {
            int dig = num % 16;
            char c;
            if(dig >= 10) {
                c = dig - 10 + 'a';
            } else {
                c = dig + '0';
            }
            res += c;
            num /= 16;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};