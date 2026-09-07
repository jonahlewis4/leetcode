class Solution {
    pair<int, int> middle_element(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size() % 2 == 1) {
            return {nums[nums.size()/2], nums[nums.size()/2]};
        }
        return {nums[nums.size()/2], nums[nums.size()/2-1]};
    }
public:
    int minMoves2(vector<int>& nums) {
        pair<int, int> targ = middle_element(nums);

        int res1 = 0;
        int res2 = 0;
        for(const int num : nums) {
            res1 += abs(num - targ.first);
            res2 += abs(num - targ.second);
        }  
        return min(res1, res2);     
    }
};