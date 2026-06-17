class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3) {
            return false;
        }
        vector<int> smallestBefore(nums.size());
        vector<int> largestBefore(nums.size());
        int smallest = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            smallestBefore[i] = smallest;
            smallest = min(smallest, nums[i]);
        }
        int largest = INT_MIN;
        for(int i = nums.size() - 1; i >= 0; i--) {
            largestBefore[i] = largest;
            largest = max(largest, nums[i]);
        }
 
        for(int i = 1; i <= nums.size() - 2; i++) {
            if(smallestBefore[i] < nums[i] && largestBefore[i] > nums[i]) {
                return true;
            }
        }

        return false;
    }
};