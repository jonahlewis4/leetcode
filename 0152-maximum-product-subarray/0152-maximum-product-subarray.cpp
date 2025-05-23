class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int smallestNeg = 1;
        int largestPos = 1;

        int res = INT_MIN;

        for(const auto & num : nums){
            int oldLargest = largestPos;
            largestPos = max({smallestNeg * num, largestPos * num, num});
            smallestNeg = min({smallestNeg * num, oldLargest * num, num});
            res = max(largestPos, res);

    
        }

        return res;


    }
};