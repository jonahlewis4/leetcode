class Solution {
private: 
    struct digitInfo{
        int leftMostNon9 = -1;
        int leftMost = -1;
        int leftMostNon1or0 = -1;
    };

    digitInfo calculateDigitInfo(int num) const {
        digitInfo info;
        while(num > 0){
            int digit = num % 10;
            if(digit != 9){
                info.leftMostNon9 = digit;
            }
            if(digit != 1 && digit != 0) {
                info.leftMostNon1or0 = digit;
            }
            info.leftMost = digit;
            num /= 10;
        }
        return info;
    }

    struct bigSmall {
        int biggest = 0;
        int smallest = 0;
    };

    bigSmall getBiggestSmallest(digitInfo info, int num) const {
        bigSmall res;
        int multiplier = 1;
        while(num > 0){
            int digit = num % 10;
            if(digit == info.leftMostNon9) {
                res.biggest += 9 * multiplier;
            } else {
                res.biggest += digit * multiplier;
            }

            if(info.leftMost != 1) {
                if(digit == info.leftMost) {
                    res.smallest += 1 * multiplier;
                } else {
                    res.smallest += digit * multiplier;
                }
            } else /*if leftMost is 1 zero the leftmost non 1*/ {
                if(digit == info.leftMostNon1or0) {
                    res.smallest += 0 * multiplier; // unecessary line, but left in for consistency
                } else {
                    res.smallest += digit * multiplier;
                }
            }

            multiplier *= 10;
            num /= 10;
        }
        return res;
    }

public:
    int maxDiff(int num) {
        digitInfo info = calculateDigitInfo(num);
        
        bigSmall bigSmall = getBiggestSmallest(info, num);
        return bigSmall.biggest - bigSmall.smallest;
    }
};