class Solution {
    static int flip(int i) {
        bool asBool = (bool)i;
        bool flipped = !asBool;
        return (int)flipped;
    }
    static bool swapNextThree(vector<int>& nums, int i) {
        if(i + 2 >= nums.size()) {
            return true;
        }
        nums[i] = flip(nums[i]);
        nums[i + 1] = flip(nums[i + 1]);
        nums[i + 2] = flip(nums[i + 2]);
        return false;
    }
public:
    int minOperations(vector<int>& nums) {
        int swaps = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                swaps++;
                bool oob = swapNextThree(nums, i);
                if(oob) {
                    return -1;
                }
            }
        }
        return swaps;
    }
};