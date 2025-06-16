class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int largest = nums.back();
        int maxDiff = INT_MIN;
        for(int i = nums.size() - 2; i >= 0; i--){

            int diff = largest - nums[i];
            if(diff > 0 ){
                maxDiff = max(diff, maxDiff);
            }
        
            largest = max(largest, nums[i]);
        }


        return maxDiff == INT_MIN ? -1 : maxDiff;
        

    }
};