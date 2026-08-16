class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int total = 0;
        if(nums.size() < 3) {
            return 0;
        }
        int prevDiff = nums[1] - nums.front();
        int streak = 0;
        for(int i = 2; i < nums.size(); i++) {
            int curDiff = nums[i] - nums[i - 1];
            if(curDiff == prevDiff){
                streak++;
                total += streak;
            } else {
                streak = 0;
            }
            prevDiff = curDiff;
            
        }
        return total;
    }
};