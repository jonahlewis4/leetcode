class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans(nums.size() / 3, vector<int>(3));
        for(int i = 0; i < nums.size(); i++){
            int arrIndex = i / 3;
            int subIndex = i % 3;
            if(subIndex > 0 && nums[i] - ans[arrIndex][0] > k){
                return {};
            }
            ans[arrIndex][subIndex] = nums[i];
        }
        return ans;
    }
};