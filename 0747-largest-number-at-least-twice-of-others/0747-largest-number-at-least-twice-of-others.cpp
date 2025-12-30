class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int largest = max(nums.front(), nums[1]);
        int secondLargest = min(nums.front(), nums[1]);

        int largestI = nums.front() > nums[1] ? 0 : 1;

        for(int i = 2; i < nums.size(); i++) {
            if(nums[i] > largest) {
                secondLargest = largest;
                largest = nums[i];
                largestI = i;
            } else if (nums[i] > secondLargest) {
                secondLargest = nums[i];
            }
        }

        return largest >= secondLargest * 2 ? largestI : -1;
    }
};