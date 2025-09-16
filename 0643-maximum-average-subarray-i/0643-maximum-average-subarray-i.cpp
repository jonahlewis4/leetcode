class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        for(int i = 0; i < k; i++) {
            sum += nums[i];

        }
            int bestSum = sum;

        for(int i = k; i < nums.size(); i++) {
            sum -= nums[i - k];
            sum += nums[i];
            bestSum = max(bestSum, sum);
        }
        bestSum = max(bestSum, sum);
        return (double) bestSum / k;
    }
};