class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int weakestDelta = INT_MAX;

        int flips = 0;
        long long total = 0;
        for(const auto & num : nums) {
            int flipped = num ^ k;
            if(flipped >= num){
                flips++;
                total += flipped;
                
                int delta = flipped - num;


                if(delta < weakestDelta) {
                    weakestDelta = delta;
                }

            
            } else {
                total += num;
                int delta = num - flipped;
                if(delta < weakestDelta) {
                    weakestDelta = delta;
                }
            }
        }
        if(flips %2 == 0){
            return total;
        } 
        return total - weakestDelta;
    }
};