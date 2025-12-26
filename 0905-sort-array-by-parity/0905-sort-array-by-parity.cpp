class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const int a, const int b) {
            int p1 = a & 1;
            int p2 = b & 1;

            return p1 < p2;
        });

        return nums;
    }
};