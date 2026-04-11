class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int maxElement = *max_element(nums.begin(), nums.end());
        return maxElement * k + (k * (k - 1))/2;
    }
};