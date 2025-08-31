class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0]; 
        int sum = 0;
        for(const auto & num : nums) {
            sum += num;
            maxSum = max(maxSum, sum);
            sum = max(0, sum);
        }
        return maxSum;
    }
};