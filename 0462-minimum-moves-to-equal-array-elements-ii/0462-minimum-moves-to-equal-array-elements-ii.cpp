class Solution {
    int middle_element(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
public:
    int minMoves2(vector<int>& nums) {
        int targ = middle_element(nums);

        int res1 = 0;
                for(const int num : nums) {
            res1 += abs(num - targ);
        }  
        return res1;     
    }
};