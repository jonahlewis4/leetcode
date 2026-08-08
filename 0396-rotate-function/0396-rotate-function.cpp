class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int finalNumI = nums.size() - 1;
        int lSum = 0;
        long long F = 0;
        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            lSum += num;
            F += (long long)i * num;
        }
        lSum -= nums[finalNumI];

        long long maxF = F;
        for(int shift = 1; shift < nums.size(); shift++) {
            //when shift is 1, every number is 1 right of where it should be.
            F -= (nums.size() - 1) * nums[finalNumI];
            finalNumI--;

            F += lSum;
            maxF = max(F, maxF);
            lSum += nums[finalNumI + 1];
            lSum -= nums[finalNumI];
        }

        return maxF;
    }
};