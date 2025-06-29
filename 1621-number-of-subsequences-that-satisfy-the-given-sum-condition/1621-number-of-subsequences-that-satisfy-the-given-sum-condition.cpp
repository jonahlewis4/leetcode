class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int MOD = 1e9 + 7;

        vector<int> powers(nums.size(), 0);
        powers[0] = 1;
        for(int i = 1; i < powers.size(); i++) {
            powers[i] = (powers[i - 1] * 2) % MOD;
        }


        int l = 0;
        int r =  nums.size() - 1;
        int ans = 0;
        while(l <= r) {
            int sum = nums[l] + nums[r];
            if(sum <= target) {
                int dist = r - l;
                ans += powers[dist];
                ans %= MOD;
                l++;
            } else {
                r--;
            }
        }

        return ans;
    }
};