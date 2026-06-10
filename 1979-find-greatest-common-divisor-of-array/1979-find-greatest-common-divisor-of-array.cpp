class Solution {
public:
    int findGCD(const vector<int>& nums) {
        auto [small, big] = minmax_element(nums.begin(), nums.end());
        return gcd(*small, *big);
    }
};