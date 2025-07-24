class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        auto l = nums.begin();
        int sum = 0;
        while(l < nums.end()) {
            sum += *l;
            l+=2;
        }
        return sum;
    }
};