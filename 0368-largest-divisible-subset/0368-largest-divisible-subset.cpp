class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        //sort nums
        //nums which it can fit in

        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size());
        vector<int> backtrack(nums.size());

        for(int i = 0; i < nums.size(); i++) {
            int iNum = nums[i];
            int best = 0;
            int bestI = 0;
            for(int j = 0; j < i; j++) {
                int jNum = nums[j];
                
                if(iNum % jNum == 0){
                    int prev = dp[j];
                    if(prev > best){
                        best = prev;
                        bestI = j;
                    }
                }
            }
            dp[i] = best + 1;
            backtrack[i] = bestI;
        }

        const vector<int>::iterator& itr = max_element(dp.begin(), dp.end());

        int j = itr - dp.begin();

        vector<int> res(dp[j]);
        for(int i = res.size() - 1; i >= 0; i--) {
            res[i] = nums[j];
            j = backtrack[j];
        }
        return res;
    }
};