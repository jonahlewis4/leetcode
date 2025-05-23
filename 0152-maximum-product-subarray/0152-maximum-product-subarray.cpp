class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        
        int smallestNeg = 1;
        int largestPos = 1;

        int res = INT_MIN;

        for(const auto & num : nums){
            int oldLargest = largestPos;
            largestPos = max({smallestNeg * num, largestPos * num});
            smallestNeg = min({smallestNeg * num, oldLargest * num});
            res = max(largestPos, res);

            largestPos = max(largestPos, 1);
            smallestNeg = min(smallestNeg, 1);
        }

        return res;


    }
};