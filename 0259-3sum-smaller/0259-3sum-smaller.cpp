class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int res = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            int t2 = target - nums[i];
            //find values such that smaller
            int r = nums.size() - 1;
            for(int l = i + 1; l < r; l++){
                while(r > l && nums[l] + nums[r] >= t2){
                    r--;
                }
                res += r - l;
            }
        }
        return res;
    }
};