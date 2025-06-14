class Solution {
public:
    int minMaxDifference(int num) {
        int biggest = replaceLeftMostNon9With9(num);
        int smallest = replaceLeftMostWith0(num);
        return biggest - smallest;
    }

    int replaceLeftMostNon9With9(int num) const {
        int digitToReplace = leftMostNon9(num);
        return replaceAll(num, digitToReplace, 9);
    }
    int leftMostNon9(int num) const {
        int ans = -1;
        
        while(num > 0){
            int digit = num % 10;
            if(digit != 9){
                ans = digit;
            }
            num /=10;
        }
        return ans;
    }
    int replaceLeftMostWith0(int num) const {
        int digitToReplace = leftMost(num);
        return replaceAll(num, digitToReplace, 0);
    }

    int leftMost(int num) const {
        int ans = -1;
        while(num > 0){
            int digit = num % 10;
            ans = digit;
            num /= 10;
        }
        return ans;
    }

    int replaceAll(int num, int digitToReplace, int replacer) const {
        int replaced = 0;
        int multiplier = 1;
        while(num > 0) {
            int digit = num % 10;
            if(digit == digitToReplace) {
                digit = replacer;
            }
            replaced += digit * multiplier;
            multiplier *= 10;
            num /=10;
        }
        return replaced;
    }
};