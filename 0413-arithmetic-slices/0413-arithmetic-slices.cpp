class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int total = 0;
        for(int i = 0; i + 2 < nums.size(); i++) {
            int prevDiff = nums[i+1] - nums[i];
            for(int j = i + 2; j < nums.size(); j++) {
                int curDiff = nums[j] - nums[j-1];
                if(prevDiff == curDiff) {
                    total++;
                } else {
                    break;
                }
            }
        }
        return total;
    }
};