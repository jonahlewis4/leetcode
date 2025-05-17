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

    inline bool subsetSum(const vector<int>& nums, int target) const {

        bitset<10001> dp; 
        dp[0] = 1;

        for (int num : nums) {
            bitset<10001> orSet = dp << num;
            dp |= orSet;
        }

        return dp[target];
    }
};
        
    