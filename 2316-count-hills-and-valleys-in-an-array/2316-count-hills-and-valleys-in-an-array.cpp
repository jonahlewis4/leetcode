class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int total = 0;
        int last = nums[0];
        for(int i = 1; i < nums.size() - 1; i++) {
            if(nums[i + 1] == nums[i]) {
                continue;
            }
            if(last < nums[i] && nums[i] > nums[i + 1]) {
                total++;
            }
            if(last > nums[i] && nums[i] < nums[i + 1]) {
                total++;
            }
            last = nums[i];
        }
        return total;
    }
};