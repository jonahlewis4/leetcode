class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 0){
            return false;
        }
        if(n == 1){
            return true;
        }
        if(n % 4) {
            return false;
        } 
        n /= 4;
        if(isPowerOfFour(n)){
            return true;
        }
        return false;
    }
};