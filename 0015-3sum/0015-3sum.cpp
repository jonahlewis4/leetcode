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
                }
                if(sum > goal){
                    while(r - 1 > l && nums[r] == nums[r - 1]){
                        r--;
                    }
                    r--;
                }  else {
                    while(l + 1 < r && nums[l+ 1] == nums[l]){
                        l++;
                    }
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