class Solution {
    vector<int> s;
    unordered_set<int> set;
    int r(int i, vector<int>& nums){
        if(s[i] > 0) {
            return 1 + s[i];
        }
        if(set.contains(nums[i])) {
            return 0;
        }
        set.insert(nums[i]);
        int res = 1 + r(nums[i], nums);
        set.erase(nums[i]);
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