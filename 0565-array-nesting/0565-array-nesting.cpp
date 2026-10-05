class Solution {
    vector<int> s;
    int r(int i, vector<int>& nums){
        if(s[i] > 0) {
            return s[i] + 1;
        }
        if(nums[i] < 0) {
            return 0;
        }
        int next = nums[i];
        nums[i] = -nums[i] - 1;
        int res = 1 + r(next, nums);
        nums[i] = next;
        s[i] = res;
        return res;
    }
public:
    int arrayNesting(vector<int>& nums) {
        s.resize(nums.size(), -1);
        for(int i = 0; i < nums.size(); i++) {
            r(i, nums);
        }
        return *max_element(s.begin(), s.end());
    }
};