class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int minSum = 0;
        int maxSum = 0;

        int sum = 0;
        for(const auto & num : nums){
            sum += num;
            minSum = min(sum, minSum);
            maxSum = max(sum, maxSum);
        }

        return maxSum - minSum;
    }
};