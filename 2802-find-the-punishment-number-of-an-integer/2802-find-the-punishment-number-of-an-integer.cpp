class Solution {
public:
    int punishmentNumber(int n) {
        int res = 0;
        for(int i = 1; i <= n; i++){
            if(selfSumming(i)){
                res += i * i;
            }
        }
        return res;
    }
    bool selfSumming(int i) const {
        return recurse(i * i, i);
    }

    //recurse return true if there is a parititon of digits
    //that sums up to total.
    bool recurse(int digits, int total) const{
        if(total == 0 && digits == 0){
            return true;
        }
        if(total < 0){
            return false;
        }

        int rightSum = 0;
        int tenPow = 1;
        while(digits > 0){
            int rightMost = digits % 10;
            rightSum += rightMost * tenPow;
            tenPow *= 10;
            digits /= 10;
            
            if(recurse(digits, total - rightSum)){
                return true;
            }
        }
        return false;
    }

};