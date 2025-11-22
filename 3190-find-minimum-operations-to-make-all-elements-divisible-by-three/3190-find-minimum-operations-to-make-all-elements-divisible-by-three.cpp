class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ops = 0;
        for(const int num : nums) {
            int m3 = num % 3;
            ops += min(m3, 1);
        }
        return ops;
    }
};