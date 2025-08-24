class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zCount = 0;
        int l = 0;
        int r = 0;

        int longest = 0;
        while(r < nums.size()) {
            int rightVal = nums[r];
            if(rightVal == 0) {
                zCount++;
                while(zCount == 2){
                    if(nums[l] == 0) {
                        zCount--;
                    }
                    l++;
                }
            }
            longest = max(longest, r - l + 1);
            r++;
        }
        return longest - 1;
    }
};