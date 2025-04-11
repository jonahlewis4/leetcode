class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        // x bubble sort but we also need to check if swaps are allowed
        // better: check that each in a run of swappables is allways larger than the max of all previous runs.

        //______ __________ ________

        int maximum = INT_MIN;
        int localMax = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(cannotSwap(nums[i], nums[i - 1])){
                maximum = localMax;
                localMax = nums[i];
            }
            if(nums[i] < maximum){
                return false;
            }
            localMax = max(localMax, nums[i]);
            
        }
        return true;
    }
    bool cannotSwap(int a, int b){
        return __builtin_popcount(a) != __builtin_popcount(b);
    }
};