class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int MOD = 1e9 + 7;

        vector<int> powers(nums.size(), 0);
        powers[0] = 1;
        for(int i = 1; i < powers.size(); i++) {
            powers[i] = (powers[i - 1] * 2) % MOD;
        }


        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            int comp = target - num;
            auto endItr = upper_bound(nums.begin(), nums.end(), comp);
            int endI = endItr - nums.begin();
            
            int maxLen = endI - i;
            if(maxLen < 1) {
                continue;
            }
            ans += powers[maxLen - 1];
            ans %= MOD;
        }
        return ans;
    }
};