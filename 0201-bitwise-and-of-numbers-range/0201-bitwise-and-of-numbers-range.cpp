class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int start = 0x40000000;
        int res = 0;
        while(start > 0) {
            if((left & start) == (right & start)){
                res |= (left & start); 
            } else {
                return res;
            }
            start /= 2;
        }
        return res;
    }
};