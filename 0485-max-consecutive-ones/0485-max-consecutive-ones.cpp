class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int streak = 0;
        int maxStreak = 0;
        for(const int num : nums){
            if(num == 1){
                streak++;
                maxStreak = max(maxStreak, streak);
            } else {
                streak = 0;
            }
        }
        return maxStreak;
    }
};