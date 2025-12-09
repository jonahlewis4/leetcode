class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> freq;

        for(const int num : nums) {
            freq[num]++;
        }

        int res = 0;
        constexpr int MOD = (int)(1e9) + 7;


        unordered_map<int, int> runFreq;
        for(const int num : nums) {
            int twice = num * 2;

            int beforeCount = runFreq[twice];
            int afterCount = freq[twice] - runFreq[twice];
            if(num == 0) {
                afterCount--;
            }

            long long delta = (long long)afterCount * beforeCount;
            delta %= MOD;

            res += delta;
            res %= MOD;

            runFreq[num]++;
        }
        

        return res;
    }
};