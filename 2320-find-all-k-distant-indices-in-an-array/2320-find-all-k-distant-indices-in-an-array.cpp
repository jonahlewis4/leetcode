class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int rightMost = -k - 1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == key){
                rightMost = i;
            }
            if(abs(i - rightMost) <= k){
                nums[i] = -abs(nums[i]);
            }
        }
        int leftMost = nums.size() + k;
        for(int i = nums.size() - 1; i >= 0; i--){
            if(abs(nums[i]) == key) {
                leftMost = i;
            }
            if(abs(i - leftMost) <= k) {
                nums[i] = -abs(nums[i]);
            }
        }
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if(num < 0) {
                res.push_back(i);
            }
        }
        return res;


        return {};
    }
};