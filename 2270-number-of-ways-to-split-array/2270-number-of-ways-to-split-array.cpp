class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long lSum = 0;
        long long rSum =  accumulate(nums.begin(), nums.end(), 0l);
        int res = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            lSum += nums[i];
            rSum -= nums[i];
            
            if(lSum >= rSum){
                res++;
            }
        }

        return res;
    }
};