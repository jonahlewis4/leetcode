class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        vector<int> largestAfter(nums.size());
        int largest = INT_MIN;
        for(int i = nums.size() - 1; i >= 0; i--){
            largestAfter[i] = largest;
            largest = max(largest, nums[i]);
        }

        int maxDiff = INT_MIN;

        for(int i = 0; i < nums.size() - 1; i++) {
            int compliment = largestAfter[i];
            int diff = compliment - nums[i];
            if(diff > 0) {
                maxDiff = max(diff, maxDiff);
            }
        }

        return maxDiff == INT_MIN ? -1 : maxDiff;

    }
};