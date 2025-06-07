class Solution {
    vector<vector<int>> dp;
    vector<int> nums;

    int compute(int l, int r) {
        if (dp[l][r] != -1){
            return dp[l][r];
        }
        int best = 0;
        for(int i = l + 1; i < r; i++){
            int left = compute(l, i);
            int right = compute(i, r);
            int valIfLast = left + right + nums[l] * nums[i] * nums[r];
            best = max(best, valIfLast);
        }
        dp[l][r] = best;
        return best;
    }

public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        int k = n + 2;

        nums.resize(k);
        for(int i = nums.size() - 2; i >= 1; i--){
            nums[i] = nums[i - 1];
        }
        nums.back() = 1;
        nums[0] = 1;
        this->nums = nums;
        dp.resize(k, vector<int>(k, -1));

        return compute(0, dp.size() - 1);
    }
};