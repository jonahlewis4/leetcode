class Solution {
public:
    int minSteps(int n) {
        int factor = 2;
        int res = 0;
        while(n > 1) {
            if(n%factor == 0){
                n/=factor;
                res+=factor;
            } else {
                factor++;
            }
        }

        return res;
    }
};