class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> vals;
        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int comp = target - num;
            if(vals.find(comp) != vals.end()) {
                return {i, vals[comp]};
            }
            vals[num] = i;
        }
        return {};

    }
};