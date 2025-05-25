class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        sub.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++){
            auto pos = lower_bound(sub.begin(), sub.end(), nums[i]);
            if(pos == sub.end()){
                sub.push_back(nums[i]);
            } else {
                if (nums[i] < *pos){
                    *pos = nums[i];
                }
            }
        }
        return sub.size();
    }
};