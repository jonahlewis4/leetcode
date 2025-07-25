class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> in;
        int sum = 0;
        for(const auto & num : nums) {
            if(num < 0) {
                continue;
            }
            if(in.find(num) == in.end()) {
                sum += num;
                in.insert(num);
            }
        }
        if(sum == 0) {
            return *max_element(nums.begin(), nums.end());
        }
        return sum;
    }
};