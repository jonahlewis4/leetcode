class Solution {
    vector<vector<int>> cache;
    int maxScore(int totalPoints, int l, int r, vector<int>& nums) {
        if(l > r) {
            return 0;
        }

        if(cache[l][r] != -1) {
            return cache[l][r];
        }
        int opLeft = maxScore(totalPoints - nums[l], l+1, r, nums);
        int ourLeftPoints = totalPoints - opLeft;

        int opRight = maxScore(totalPoints - nums[r], l, r - 1, nums);
        int ourRightPoints = totalPoints - opRight;

        int res = max(ourLeftPoints, ourRightPoints);
        cache[l][r] = res;
        return res;
        
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        cache.resize(nums.size(), vector<int>(nums.size(), -1));
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int bestScore = maxScore(sum, 0, nums.size() - 1, nums);
        int opScore = sum - bestScore;
        return bestScore >= opScore;
    }
};