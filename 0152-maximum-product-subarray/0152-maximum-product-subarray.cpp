class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int negative = 1;
        int positive = 1;

        int res = INT_MIN;
        for(const auto & num : nums){
            int oldPos = positive;
            positive = max({num * oldPos, num * negative, num});
            negative = min({num * oldPos, num * negative, num});
            res = max(res, positive);
        }
        return res;
    }
};