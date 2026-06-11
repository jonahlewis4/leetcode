class Solution {
        
    static bool r(string&  num, unsigned long long lVal, unsigned long long rVal, int rBack){
        if(rBack == num.size() - 1) {
            return false;
        }
        unsigned long long sum = lVal + rVal;
        unsigned long long test = 0;
        
        bool res = false;
        for(int i = rBack + 1; i < num.size(); i++) {
            int digit = num[i] - '0';
            test *= 10;
            test += digit;
            if(test > sum) {
                break;
            }
            if(test == sum) {
                
                if(i == num.size() - 1) {
                    return true;
                }
                
                res |= r(num, rVal, sum, i);
                if(res) {
                    return res;
                }
            }
            if(test == 0) {
                break;
            }
        }
   

        return res;
    }
public:
    bool isAdditiveNumber(string num) {
        unsigned long long l = 0;
        bool res = false;
        for(int i = 0; i + 2 < num.size(); i++) {
            l *= 10;
            int digit = num[i] - '0';
            l += digit;
            if(l > (long long)INT_MAX * 2) {
                return false;
            }

            unsigned long long rVal = 0;
            for(int j = i + 1; j + 1 < num.size(); j++) {
                rVal *= 10;
                int rDigit = num[j] - '0';
                rVal += rDigit;
                res |= r(num, l, rVal, j);
                if(res) {
                    return true;
                }
                if(rVal == 0 ){
                    break;
                }
            }
            if(l == 0) {
                break;
            }
        }
        return res;
    }
};