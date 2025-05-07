class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        
        vector<vector<int>> res;

        
        int previous = lower - 1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != previous + 1){
                res.push_back({previous + 1, nums[i] - 1});
            }
            previous = nums[i];
        }
        if(previous != upper){
            res.push_back({previous + 1, upper});
        }
        return res;
    }
};