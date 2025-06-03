class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int cnt = 0;
        solve(nums, target, 0, 0, cnt);
        return cnt;
    }

    void solve(vector<int>& nums, int target, int idx, int sum, int& cnt) {
        if (idx == nums.size()) {
            if (sum == target) {
                cnt++;
            }
            return;
        }

        solve(nums, target, idx + 1, sum + nums[idx], cnt); 
        solve(nums, target, idx + 1, sum - nums[idx], cnt);

    }
};
