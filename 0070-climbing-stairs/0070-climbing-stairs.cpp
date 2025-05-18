class Solution {
public:
    int climbStairs(int n) {
        int oneAgo = 1;
        int twoAgo = 0;

        for(int i = n - 1; i >= 0; i--){
            int newValue = oneAgo + twoAgo;
            twoAgo = oneAgo;
            oneAgo = newValue;
        }
        return oneAgo;
    }
};