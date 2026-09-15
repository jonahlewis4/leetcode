class Solution {
    int maxScore(int totalPoints, int l, int r, vector<int>& nums) {
        if(l > r) {
            return 0;
        }
        int opLeft = maxScore(totalPoints - nums[l], l+1, r, nums);
        int ourLeftPoints = totalPoints - opLeft;

        int opRight = maxScore(totalPoints - nums[r], l, r - 1, nums);
        int ourRightPoints = totalPoints - opRight;

        return max(ourLeftPoints, ourRightPoints);
        
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int bestScore = maxScore(sum, 0, nums.size() - 1, nums);
        int opScore = sum - bestScore;
        return bestScore >= opScore;
    }
};