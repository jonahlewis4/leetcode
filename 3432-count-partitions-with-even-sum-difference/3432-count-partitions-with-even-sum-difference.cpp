class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int lSum = 0;
        int res = 0;
        for(int i = 0; i < nums.size() - 1; i++ ){
            int num = nums[i];
            lSum += num;
            sum -= num;
            int diff = sum - lSum;
            if(diff % 2 == 0) {
                res++;
            }
        }

        return res;
    }
};