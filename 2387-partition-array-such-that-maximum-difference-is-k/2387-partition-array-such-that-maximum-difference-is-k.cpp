class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        ans.push_back({nums[0]});
        for(const auto & num : nums) {
            if(num - ans.back().front() > k){
                ans.push_back({num});
            }
        }


        return ans.size();
    }
};