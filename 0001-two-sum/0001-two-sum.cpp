class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        for(int i = 0; i < nums.size(); i++) {
            int currentNum = nums[i];
            int comp = target - nums[i];
            if(seen.contains(comp)) {
                return {seen[comp], i};
            }
            seen[currentNum] = i;
        }

        return {0,0};
    }
};