class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        if(nums.size() == 2){
            return min(nums[0], nums[1]);
        }
        
        int l = 0;
        int r = nums.size() - 1;
        
        while(l <= r){
            int m = (l + r) / 2;
            int rVal = m + 1 < nums.size() ? nums[m + 1] : nums[0];
            if(nums[m] >= nums[0] && rVal < nums[0]){
                return rVal;
            } else if (nums[m] < nums[0]){
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return nums[0];
    }
};