class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {

        int l = nums.size();
        int r = 0;
        int high = nums.front();
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < high) {
                r = i;
            }
            high = max(high, nums[i]);
        }
        int low = nums.back();
        for(int i = nums.size() - 1; i >= 0; i--) {
            if(nums[i] > low) {
                l = i;
            }
            low = min(low, nums[i]);
        }
        if(r == 0) {
            return 0;
        }
        return r - l + 1;
    }
};