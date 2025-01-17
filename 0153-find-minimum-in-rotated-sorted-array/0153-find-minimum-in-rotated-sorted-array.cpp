class Solution {
public:
    int findMin(vector<int>& nums) {
        int minVal = nums[0];   

        int l = 0;
        int r = nums.size() - 1;
        while(l <= r){
            int m = (l + r) / 2;

            if(nums[m] < minVal){
                minVal = nums[m];
            }

            if(nums[0] <= nums[m]){  
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return minVal;
    }
};