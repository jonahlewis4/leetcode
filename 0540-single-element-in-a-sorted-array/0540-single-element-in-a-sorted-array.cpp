class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r){
            int m = (l + r) / 2;
            int leftVal = m - 1 >= 0 ? nums[m - 1] : INT_MIN;
            int rightVal = m + 1 < nums.size() ? nums[m + 1] : INT_MIN;

            if(leftVal != nums[m] && rightVal != nums[m]){
                return nums[m];
            }

            //determine the index of the right most duplicate.
            int rightMostDuplicateIdx;
            if (rightVal == nums[m]){
                rightMostDuplicateIdx = m + 1;
            }
            else {
                rightMostDuplicateIdx = m;
            }

            if (rightMostDuplicateIdx % 2 == 0){
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return -1;
    }
};