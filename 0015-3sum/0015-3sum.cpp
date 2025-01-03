class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());

        std::vector<vector<int>> res;
        for(int i = 0; i < nums.size() - 2; i++){
            int first = nums[i];
            int target = 0 - nums[i];

            int l = i + 1;
            int r = nums.size() - 1;

            while(l < r){
        


                int sum = nums[l] + nums[r];

                if(sum == target){
                    res.push_back({first, nums[l], nums[r]});
                    l++;
                    while(l < r && nums[l] == nums[l - 1]){
                        l++;
                    }
                }
                if( sum < target){
                    l++;
                } else {
                    r--;
                }

                
                // while(r > l && r + 1 < nums.size() && nums[r] == nums[r + 1]){
                //     r--;
                // }
            }

            while(i + 1 < nums.size() && nums[i + 1] == nums[i]){
                i++;
            }
        }
        return res;
    }
};