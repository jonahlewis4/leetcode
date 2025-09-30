class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while(nums.size() > 1) {
            int n = nums.size();
            int prev = nums.back();

            for(int i = 0; i < n - 1; i++){
                int r = n - i - 1;
                int nextPrev = nums[r - 1];
                nums[r - 1] += prev;
                nums[r - 1] = nums[r - 1] % 10;
                prev = nextPrev;
            }
            nums.pop_back();
        }
        return nums.front();
    }
};  