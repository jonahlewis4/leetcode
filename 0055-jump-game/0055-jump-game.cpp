class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lastPossible = nums.size() - 1;
        for(int i = nums.size() - 2; i >= 0; i--) {
            lastPossible = i + nums[i] >= lastPossible ? i : lastPossible;
        }
        return !lastPossible;
    }
};