class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) {
            return 1;
        }
        
        int total = 10;
        int last = 9;
        for(int i = 2; i <= n; i++) {
            last = last * (11 - i);
            total += last;
        }

        return total;
         

    }
};