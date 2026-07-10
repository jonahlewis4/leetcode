class Solution {
private:
    static int modPow(int a, int power) {
        a %= 1337;
        int result = 1;
        while(power > 0) {
            if(power & 1) {
                result *= (a);
                result %= 1337;
            }
            a = (a * a) % 1337;
            power >>= 1;
        }
        return result;
    }
public:
    int superPow(int a, vector<int>& b) {
        int result = 1;
        for(const int digit : b) {
            result = (modPow(result, 10) * modPow(a, digit) )%1337;
        }

        return result;
    }
};