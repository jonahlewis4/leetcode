class NumArray {
    vector<int> prefix;
public:
    NumArray(vector<int>& nums) {
        prefix.resize(nums.size() + 1);
        prefix[0] = 0;
        for(int i = 1; i < prefix.size(); i++){
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
    }
    
    int sumRange(int left, int right) {
        const auto & _prefix = prefix;
        return prefix[right + 1] - prefix[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */