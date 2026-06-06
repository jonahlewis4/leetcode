class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> res(nums.size());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int lSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            int rSum = sum - nums[i] - lSum;
            res[i] = abs(lSum - rSum);
            lSum += nums[i];
        }
        return res;
    }
};