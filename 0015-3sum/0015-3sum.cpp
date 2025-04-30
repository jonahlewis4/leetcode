class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < nums.size(); i++){
            int l = i + 1;
            int r = nums.size() - 1;
            while(l < r){
                int goal = 0 - nums[i];
                int sum = nums[l] + nums[r];
                if(sum == goal){
                    res.push_back({
                        nums[i],
                        nums[l],
                        nums[r],
                    });
                    while(l + 1 < r && nums[l] == nums[l + 1]){
                        l++;
                    }
                    l++;
                }
                else if(sum > goal){
                    r--;
                }  else { 
                    l++;
                }
            }
            while(i + 1 < nums.size() && nums[i + 1] == nums[i]){
                i++;
            }
        }
        return res;
    }
};