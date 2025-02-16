class Solution {
private:
    static vector<int> dp;


public:
    int fib(int n) {
        
        while(n > dp.size() - 1){
            int i = dp.size();
            dp.push_back(dp[i - 1] + dp[i - 2]);
        }

        return dp[n];

    }
};

vector<int> Solution::dp = {0, 1};