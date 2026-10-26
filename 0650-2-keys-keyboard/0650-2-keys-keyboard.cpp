class Solution {
public:
    int minSteps(int n) {
        int factor = 2;
        int res = 0;
        while(n > 1) {
            while(n%factor == 0){
                n/=factor;
                res+=factor;
            } 
            factor++;
        }

        return res;
    }
};