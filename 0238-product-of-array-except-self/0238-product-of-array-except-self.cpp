class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        
        res[0] = nums[0];
        for(int i = 1; i < res.size(); i++)
        {
            res[i] = res[i - 1] * nums[i];
        }        

        int right = 1;
        for(int i = res.size() - 1; i >= 1; i--){
            res[i] = res[i - 1] * right;
            right *= nums[i];
        }
        res[0] = right;
        return res;
    }
};