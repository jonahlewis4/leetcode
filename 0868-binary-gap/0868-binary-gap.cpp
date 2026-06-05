class Solution {
public:
    int binaryGap(int n) {
        if(__builtin_popcount(n) == 1) {
            return 0;
        }

        int lastOne = -1;
        int maxGap = 0;
        while(n > 0) {
            int digit = n & 1;
            cout<<digit<<endl;
            if(digit == 1) {
                if(lastOne == -1) {
                    lastOne = 1;
                } else {
                    maxGap = max(maxGap, lastOne);
                    lastOne = 1;
                }
            } else if (lastOne != -1) {
                lastOne++;
            }
            n>>=1;
        }
        return maxGap;
    }
};