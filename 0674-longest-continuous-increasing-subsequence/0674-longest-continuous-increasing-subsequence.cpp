class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int start = 0;
        int longest = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] <= nums[i - 1]) {
                longest = max(longest, i - start);
                start = i;
            }
        }
        longest = max(longest, (int)nums.size() - start);
        return longest;
    }
};