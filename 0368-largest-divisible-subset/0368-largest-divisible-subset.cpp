class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        //sort nums
        //nums which it can fit in

        sort(nums.begin(), nums.end());
        vector<pair<int, int>> dp(nums.size());

        for(int i = 0; i < nums.size(); i++) {
            int iNum = nums[i];
            int best = 0;
            int bestI = 0;
            for(int j = 0; j < i; j++) {
                int jNum = nums[j];
                
                if(iNum % jNum == 0){
                    pair<int, int>  p = dp[j];
                    if(p.first > best){
                        best = p.first;
                        bestI = j;
                    }
                }
            }
            dp[i] = {best + 1, bestI};
        }

        const auto & itr = max_element(dp.begin(), dp.end());

        int j = itr - dp.begin();

        vector<int> res(dp[j].first);
        for(int i = res.size() - 1; i >= 0; i--) {
            res[i] = nums[j];
            j = dp[j].second;
        }
        return res;
    }
};