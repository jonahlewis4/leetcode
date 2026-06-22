class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 0;
        int minSum = INT_MAX;
        for(int i : nums) {
            sum += i;
            minSum = min(sum, minSum);
        }

        return max(1, -(minSum - 1));
    }
};