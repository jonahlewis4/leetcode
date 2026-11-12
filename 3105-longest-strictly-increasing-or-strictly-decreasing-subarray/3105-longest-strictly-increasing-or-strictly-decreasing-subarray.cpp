class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int longest = 1;
        int longIncrease = 1;
        int longDecrease = 1;
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i - 1]){
                longIncrease++;
            } else {
                longIncrease = 1;
            }

            if(nums[i] < nums[i - 1]){
                longDecrease++;
            } else {
                longDecrease = 1;
            }
            longest = max({longest, longIncrease, longDecrease});
        }
        return longest;
    }
};