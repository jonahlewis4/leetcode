class Solution {
static bool isNoZero(int n) {
    while(n > 0) {
        int digit = n % 10;
        n /= 10;
        if(digit == 0) {
            return false;
        }
    }
    return true;

}
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1; true; i++){
            int comp = n - i;
            if(isNoZero(comp) && isNoZero(i)){
                return {i, comp};
            }
        }
    }
};