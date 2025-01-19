class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        
        if(nums.size() == 1){
            return nums[0];
        }
        if(nums[0] < nums[nums.size() - 1]){
            return nums[0];
        }

        while(l <= r){
            int m = (l + r) / 2;
            int left = m - 1 >= 0 ? nums[m - 1] : nums[nums.size() - 1];
            int right = m + 1 < nums.size() ? nums[m + 1] : nums[0];
            if(left > nums[m] && right > nums[m]){
                return nums[m];
            } else if (nums[0] <= nums[m]){
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return nums[0];
    }
};