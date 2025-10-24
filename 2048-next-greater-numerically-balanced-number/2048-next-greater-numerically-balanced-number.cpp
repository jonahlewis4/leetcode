class Solution {
    static bool isBeau(int n) {
        int i = n;
        vector<uint8_t> dig(10);
        while(i > 0) {
            int digit = i % 10;
            dig[digit]++;
            if(dig[digit] > digit) {
                return false;
            }
            i /= 10;
        }
        for(int i = 1; i <= 9; i++) {
            if(dig[i] > 0 && dig[i] != i) {
                return false;
            }
        }
        return true;
    }
public:
    int nextBeautifulNumber(int n) {
        for(int i = n + 1; true; i++){
            if(isBeau(i)){
                return i;
            }
        }
    }
};