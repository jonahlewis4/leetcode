class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int open = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val) {
                nums[open] = nums[i];
                open++;
            }
        }
        return open;
    }
};