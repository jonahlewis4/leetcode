class Solution {
private:    
    vector<vector<int>> dp;
    int c(int l, int r) {
        if(l == r) {
            return 0;
        }

        if(r - l == 1) {
            return min(r, l);
        }

        if(dp[l][r]){
            return dp[l][r];
        }

        int smallest = INT_MAX;
        for(int i = l + 1; i <= r - 1; i++) {
            //i is the number guessed
            int left = c(l, i - 1);
            int right = c(i + 1, r);

            int cost = i + max(left, right);
            smallest = min(cost, smallest);
        }
        dp[l][r] = smallest;
        return smallest;
    }
public:
    int getMoneyAmount(int n) {
        if(n == 1) {
            return 0;
        }
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        
        dp[n][n] = 0;
        dp[n-1][n] = n - 1;

        for(int l = n - 2; l >= 1; l--) {
            dp[l][l] = 0;
            dp[l][l+1] = l;
            for(int r = l+2; r <= n; r++) {
                // //1 2 3 4
                //1//0 1 2 ?
                //2//  0 1 3
                //3//    0 1 
                //4//      0

                int smallest = INT_MAX;
                for(int guess = l + 1; guess <= r - 1; guess++) {
                    int cost = guess + max(dp[l][guess - 1], dp[guess + 1][r]);
                    smallest = min(smallest, cost);
                }
                dp[l][r] = smallest;
            }
        }

        
        return dp[1].back();

    }
    void p(vector<vector<int>> dp) {
        int n = dp.size() - 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};