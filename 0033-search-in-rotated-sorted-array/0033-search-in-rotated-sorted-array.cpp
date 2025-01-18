class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r){
            int m = (l + r) / 2;
            if(nums[m] == target){
                return m;
            }

            if(nums[0] <= nums[m]){
                if(target < nums[0] || target > nums[m]){
                    l = m + 1;
                } else {
                    r = m  - 1;
                }
            } else{
                if(target < nums[m] || target >= nums[0]){
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
        }
        return -1;
    }
};