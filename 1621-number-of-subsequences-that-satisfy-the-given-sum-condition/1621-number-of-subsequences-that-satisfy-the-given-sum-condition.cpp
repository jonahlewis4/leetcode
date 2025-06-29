class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int MOD = 1e9 + 7;
        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            int comp = target - num;
            auto endItr = lower_bound(nums.begin(), nums.end(), comp + 1);
            int endI = endItr - nums.begin();
            
            int maxLen = endI - i;
            if(maxLen < 1) {
                continue;
            }
            ans += shiftLeftMod1e9(maxLen - 1);
            ans %= MOD;
        }
        return ans;
    }
    int shiftLeftMod1e9(int i) {
        long long res = 1;
        while(i > 0) {
            res <<= min(31, i);
            res %= (int)1e9 + 7;
            i -= 31;
        }
        return (int) res;

    }
};