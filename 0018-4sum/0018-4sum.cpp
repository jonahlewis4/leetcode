class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            for(int j = i + 1; j < nums.size(); j++){
                if(j > i + 1 && nums[j - 1] == nums[j]){
                    continue;
                }
                int l = j + 1;
                int r = nums.size() - 1;

                long newTarget = (long)target - (long)nums[i] - (long)nums[j];
                while(l < r){
                    if(nums[l] + nums[r] > newTarget){
                        r--;
                    } else if (nums[l] + nums[r] < newTarget){
                        l++;
                    } else {
                        vector<int> match = {nums[i], nums[j], nums[l], nums[r]};
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while(l + 1 < r && nums[l] == nums[l + 1]){
                            l++;
                        }
                        l++;
                    }
                }
            }
        }
        return res;
    }
};