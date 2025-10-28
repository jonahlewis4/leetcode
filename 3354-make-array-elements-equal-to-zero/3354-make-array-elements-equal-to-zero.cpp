class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int total = 0;
        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if(num == 0) {
                total += check2(nums, i, 1);
                total += check2(nums, i, -1);
            }
        }
        return total;
    }

    int check2(vector<int> nums, int i, int dir) {
        return check(nums, i, dir);
    }

    int check(vector<int>& nums, int i, int dir){
        if(i < 0 || i >= nums.size()){
            bool nonZero = false;
            for(const int num : nums) {
                if(num != 0){
                    nonZero = true;
                    break;
                }
            }

            return !nonZero;
        }

        int num = nums[i];
        if(num == 0) {
            return check(nums, i + 1 * dir, dir);
        }

        nums[i]--;
        dir = -dir;
        return check(nums, i + 1 * dir, dir);
    }
};