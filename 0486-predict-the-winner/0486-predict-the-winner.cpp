class Solution {
    // int maxScore(int totalPoints, int l, int r, vector<int>& nums) {
    //     if(l > r) {
    //         return 0;
    //     }

    //     if(cache[l][r] != -1) {
    //         return cache[l][r];
    //     }
    //     int opLeft = maxScore(totalPoints - nums[l], l+1, r, nums);
    //     int ourLeftPoints = totalPoints - opLeft;

    //     int opRight = maxScore(totalPoints - nums[r], l, r - 1, nums);
    //     int ourRightPoints = totalPoints - opRight;

    //     int res = max(ourLeftPoints, ourRightPoints);
    //     cache[l][r] = res;
    //     return res;
        
    // }
public:
    bool predictTheWinner(vector<int>& nums) {
        vector<int> cache(nums.size(), 0);
        for(int l = nums.size() - 1; l>=0; l--) {
            cache[l] = nums[l];
            int ourLeftPoints = nums[l];
            for(int r = l + 1; r < nums.size(); r++) {
                int opRight = cache[r-1];
                int opLeft = cache[r];

                int ourRightPoints = nums[r];

                int leftGain = ourLeftPoints - opLeft;
                int rightGain = ourRightPoints - opRight;

                cache[r] = max(leftGain, rightGain);
            }
        }
        return cache.back() >= 0;
    }
};