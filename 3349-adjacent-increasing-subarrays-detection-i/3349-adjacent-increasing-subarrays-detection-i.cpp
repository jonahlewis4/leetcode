class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if(k == 1) {
            return true;
        }
        int streak = 1;
        vector<bool> subarrays(nums.size(), false);
        for(int i = 1; i < nums.size(); i++) {
            int previous = nums[i - 1];
            int current = nums[i];

            if(previous >= current) {
                streak = 1;
            } else {
                streak++;
            }

            if(streak >= k){
                subarrays[i] = true;
            }
        }

        for(int i = k; i < nums.size(); i++) {
            if(subarrays[i] && subarrays[i - k]){
                return true;
            }
        }
        return false;
    }
};