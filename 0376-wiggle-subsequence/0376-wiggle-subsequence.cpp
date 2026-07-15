class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int up = 1;
        int down = 1;

        for(int i = 1; i < nums.size(); i++) {
            int upMax = 0;
            int downMax = 0;
        
            if(nums[i] < nums[i-1]) {
                up = down + 1;
            }
            if(nums[i] > nums[i-1]) {
                down = up + 1;
            }
        }
        return max(up, down);
    }
};