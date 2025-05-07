class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int positiveMax = 0;
        int negativeMax = 0;
        int maxMax = 0;
        for(const auto &num : nums){
            positiveMax += num;
            if(positiveMax < 0){
                positiveMax = 0;
            }
            negativeMax += num;
            if(negativeMax > 0){
                negativeMax = 0;
            }
            maxMax = max({maxMax, -negativeMax, positiveMax});
        }
        return maxMax;
    }
};