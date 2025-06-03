class Solution {
private:
    vector<int> nums;
public:
    int findTargetSumWays(const vector<int>& _nums, int target) {
        
        nums = _nums;
        
        int sum = 0;
        for(const auto & num : nums){
            sum += num;
        }
        
        if(abs(target) > sum) {
            return 0;
        }

        
        unordered_map<int, int> dp;
        dp[target] = 1;
        for(int r = nums.size(); r >= 1; r--){
            unordered_map<int, int> newDp;
            for(const auto & p : dp){
                int c = p.first;
                    int num = nums[r - 1];

                    int left = c - num;
                    int right = c + num;

                    if(left >= -sum && left <= sum){
                        newDp[left] = dp[c] + newDp[left];
                    }

                    if(right >= -sum && right <= sum){
                        newDp[right] = dp[c] + newDp[right];
                    }
            
            }
            dp = newDp;
        }


        return dp[0];
    }
};