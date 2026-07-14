class Solution {
private:    

public:
    int getMoneyAmount(int n) {
        if(n == 1) {
            return 0;
        }
        vector<vector<int>> dp(n, vector<int>(n));
        
        dp[n-1][n-1] = 0;
        dp[n-2][n-1] = n - 1;

        for(int l = n - 3; l >= 0; l--) {
            dp[l][l] = 0;
            dp[l][l+1] = l+1;
            for(int r = l+2; r <= n-1; r++) {
                // //1 2 3 4
                //1//0 1 2 ?
                //2//  0 1 3
                //3//    0 1 
                //4//      0

                int smallest = INT_MAX;
                for(int guess = l + 1; guess <= r - 1; guess++) {
                    int cost = guess+1 + max(dp[l][guess - 1], dp[guess + 1][r]);
                    smallest = min(smallest, cost);
                }
                dp[l][r] = smallest;
            }
        }

        return dp.front()[n-1];

    }
    
};