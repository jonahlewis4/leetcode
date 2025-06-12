class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        nums.push_back(*nums.begin());
        int bestDiff = INT_MIN;
        for(int i = 0; i + 1 < nums.size(); i++){
            bestDiff = max(bestDiff, abs(nums[i] - nums[i + 1]));
        }
        return bestDiff;
    }
};