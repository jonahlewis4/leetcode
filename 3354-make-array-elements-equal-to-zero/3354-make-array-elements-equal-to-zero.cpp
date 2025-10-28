class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int ans = 0;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;
        int rightSum = sum;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0){
                int rml = rightSum - leftSum;
                int lmr = leftSum - rightSum;
                if(rml == 0 || rml == 1) {
                    ans++;
                }

                if(lmr == 0 || lmr == 1){
                    ans++;
                }
            }
            leftSum += nums[i];
            rightSum -= nums[i];
        }

        return ans;
    }
};