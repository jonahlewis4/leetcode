class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        auto twoSum = [&res, nums](int l, int r, int target, int &i) {
            while(l < r){
                int sum = nums[l] + nums[r];
                if(sum < target){
                    l++;
                }
                else if (sum > target){
                    r--;
                }
                else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    while(l < r && nums[l] == nums[l - 1]){
                        l++;
                    }
                }
            }
            while(i + 1 < nums.size() - 2 && nums[i] == nums[i + 1]){
                i++;
            }
        };

        int n = nums.size();

        for(int i = 0; i < n - 2; i++){
            int l = i + 1;
            int r = n - 1;
            int target = 0 - nums[i];
            twoSum(l, r, target, i);

        }
        return res;
    }
};