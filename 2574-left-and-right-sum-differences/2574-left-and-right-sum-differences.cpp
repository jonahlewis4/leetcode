class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;
        vector<int> ans(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++) {
            int rightSum = sum - nums[i] - leftSum;
            int answer = abs(leftSum - rightSum);
            ans[i] = answer;
            leftSum += nums[i];
        }

        return ans;
    }
};