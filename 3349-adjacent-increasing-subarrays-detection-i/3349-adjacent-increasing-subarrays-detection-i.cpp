class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        // if(k == 1){
        //     return false;
        // }
        int lastMessUp = 0;
        int l = 0;
        for(int r = 1; r < nums.size(); r++) {
            int previous = nums[r - 1];
            int current = nums[r];
            if(previous >= current) {
                //if there's already been a mess up, go to the last mess up
                if(lastMessUp > l) {
                    l = lastMessUp;
                }
                lastMessUp = r;
            }

            //if l is too close to lastMessUp, not a valid subarray
            if(lastMessUp - l < k){
                l = lastMessUp;
            }

            if(lastMessUp - l > k) {
                l = lastMessUp - k;
            }

            if(r - l + 1 == 2 * k){
                return true;
            }
        }
        return false;
    }
};