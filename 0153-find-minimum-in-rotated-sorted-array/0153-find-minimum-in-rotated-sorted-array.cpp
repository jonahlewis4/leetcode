class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int minimum = nums[0];

        while(l <= r){
            int m = (l + r) / 2;
            minimum = min(minimum, nums[m]);
            if(nums[m] >= nums[0]){
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return minimum;
    }
};