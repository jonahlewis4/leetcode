class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> copy = nums;
        sort(nums.begin(), nums.end());

        int l = -1;
        int r = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == copy[i]) {
                l = i;
            } else {
                break;
            }
        }
        for(int i = nums.size() - 1; i >= 0; i--) {
            if(nums[i] == copy[i]) {
            } else {
                r = i;
                break;
            }
        }
        if(r == 0) {
            return 0;
        }
        return r - l;
    }
};