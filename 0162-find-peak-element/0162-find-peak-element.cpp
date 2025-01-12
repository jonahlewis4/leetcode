class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r){
            int m = (l + r) / 2;

            long leftElem = get(nums, m - 1);
            long rightElem = get(nums, m + 1);
            long midElem = get(nums, m);

            if(leftElem < midElem && rightElem < midElem){
                return m;
            } else if (rightElem > midElem){
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return 123;
    }
    long get(vector<int> &nums, int i){
        if(i < 0){
            return (long)INT_MIN - 1;
        }
        if(i >= nums.size()){
            return (long)INT_MIN - 1;
        }
        return nums[i];
    }
};