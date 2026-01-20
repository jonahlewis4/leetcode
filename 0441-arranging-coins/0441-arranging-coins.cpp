class Solution {
public:
    int arrangeCoins(int n) {
        //a^2 + a - n
        //.5a^2 + .5a - n = 0 

        //-.5 + sqrt(.25 - 2(-n)))/2

        double rows = (-.5 + sqrt(.25 + 2ll * n));
        return floor(rows);
    }
};