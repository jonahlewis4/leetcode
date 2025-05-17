class Solution {
public:
    bool canPartition(vector<int>& nums) {
        //subset sum for half the list.

        int total = 0;
        for(const auto & num : nums){
            total += num;
        }


        if(total % 2 == 1){
            return false;
        }

        total >>= 1;


        return subsetSum(nums, total);
    }

    bool subsetSum(const vector<int>& nums, int total) const {
        //start with all true.
        //have next be the old ones + each num in nums.

        vector<bool> sum(total + 1);
        sum[0] = true;

        for(const auto & num : nums){
            vector<bool> newSum = sum;
            for(int i = 0; i < sum.size(); i++){
                if(sum[i] && i + num < newSum.size()){
                    newSum[i + num] = true;
                }
            }            
            sum = newSum;
        } 

        return sum.back();
        
    }
};