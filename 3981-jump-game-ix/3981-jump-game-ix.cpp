class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());

        prefix[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            prefix[i] = max(prefix[i - 1], nums[i]);
        }

        suffix.back() = nums.back();
        for(int i = nums.size() - 2; i >= 0; i--){
            suffix[i] = min(suffix[i + 1], nums[i]);
        }

        vector<int> res(nums.size());
        res.back() = prefix.back();
        for(int i = nums.size() - 2; i >= 0; i--){
            if(prefix[i] > suffix[i + 1]){
                res[i] = res[i + 1];
            } else {
                res[i] = prefix[i];
            }
        }
        return res;
    }
};