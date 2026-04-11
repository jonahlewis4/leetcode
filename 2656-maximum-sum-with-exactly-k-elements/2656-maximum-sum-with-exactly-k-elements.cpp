class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int maxElement = nums.front();
        for(const int num : nums) {
            maxElement = max(maxElement, num);
        }

        return maxElement * k + (k * (k - 1))/2;
    }
};