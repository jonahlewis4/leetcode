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
        //1 and n
        dp.resize(n + 1, vector<int>(n + 1, 0));
        return c(1, n);
    }
};