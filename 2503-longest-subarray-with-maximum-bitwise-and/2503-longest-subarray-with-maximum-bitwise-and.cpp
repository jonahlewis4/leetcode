class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxElem = *max_element(nums.begin(), nums.end());
        int longestConsec = 0;
        int prev = maxElem - 1;
        int streak = 0;
        for(const auto & num : nums) {
            if(num != maxElem) {
                streak = 0;
                continue;
            }
            streak++;
            longestConsec = max(longestConsec, streak);
        }
        return longestConsec;
    }
};