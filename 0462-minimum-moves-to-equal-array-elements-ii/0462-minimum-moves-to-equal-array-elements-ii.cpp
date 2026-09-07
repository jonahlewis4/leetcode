class Solution {
public:
    int minMoves2(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin() + nums.size()/2, nums.end());
        int targ = nums[nums.size()/2];
        int res1 = 0;
                for(const int num : nums) {
            res1 += abs(num - targ);
        }  
        return res1;     
    }
};