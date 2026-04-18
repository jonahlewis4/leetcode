class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i * 2 < nums.size(); i++) {
            int j = i * 2;
            int k = j + 1;
            for(int l = 0; l < nums[j]; l++) {
                res.push_back(nums[k]);
            }
        }
        return res;
    }
};