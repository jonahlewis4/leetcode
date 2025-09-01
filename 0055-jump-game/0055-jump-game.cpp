class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0;
        while(i < nums.size()) {
            int newI = i;
            for(int j = 0; j <= nums[i]; j++) {
                if(i + j >= nums.size() - 1) {
                    return true;
                }
                int nextAdd = nums[i + j];
                int nextPos = i + j + nextAdd;
                int curPos = newI + nums[newI];

                if(nextPos > curPos) {
                    newI = i + j;
                }
            }
            if(newI == i) {
                return false;
            }
            i = newI;
        }
        return false;
    }
};