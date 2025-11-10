class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp = {1};
        int two = 0;
        int three = 0;
        int five = 0;
        for(int i = 1; i < n; i++) {
            int twoCand = dp[two] * 2;
            int threeCand = dp[three] * 3;
            int fiveCand = dp[five] * 5;
                
            int best = min({twoCand, threeCand, fiveCand});

            dp.push_back(best);
            if(twoCand == best){
                two++;
            } 
            if(threeCand == best) {
                three++;
            }
            if(fiveCand == best) {
                five++;
            }
        }
        return dp.back();
    }
};