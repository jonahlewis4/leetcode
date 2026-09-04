class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min = *min_element(nums.begin(), nums.end());
        int sum = 0;
        for(const int num : nums) {
            sum += num - min;
        }
        return sum;
    }
};