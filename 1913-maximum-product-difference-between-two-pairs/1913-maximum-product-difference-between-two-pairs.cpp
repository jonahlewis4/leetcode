class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int smol = nums[0] * nums[1];
        int big = nums.back() * *(nums.end() - 2);
        return big - smol;
    }
};