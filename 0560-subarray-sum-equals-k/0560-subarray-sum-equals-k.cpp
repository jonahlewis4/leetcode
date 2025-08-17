class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sumC;
        sumC[0] = 1;
        int sum = 0;
        int res = 0;
        for(const auto & num : nums) {
            sum += num;
            int search = sum - k;
            res += sumC[search];
            sumC[sum]++;
        }
        return res;
    }
};