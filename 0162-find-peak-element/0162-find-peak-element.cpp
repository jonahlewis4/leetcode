class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r){
            int m = (l + r) / 2;

            int leftElem = get(nums, m - 1);
            int rightElem = get(nums, m + 1);
            int midElem = get(nums, m);

            if(leftElem < midElem && rightElem < midElem){
                return m;
            } else if (rightElem > midElem){
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return 0;
    }
    int get(vector<int> &nums, int i){
        if(i < 0){
            return INT_MIN;
        }
        if(i >= nums.size()){
            return INT_MIN;
        }
        return nums[i];
    }
};