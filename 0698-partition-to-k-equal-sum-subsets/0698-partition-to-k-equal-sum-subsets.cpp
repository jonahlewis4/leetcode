class Solution {
    bool r(int mask, int curSum, int groupSum, const vector<int>& nums) {
        if(mask == filledMask) {
            return true;
        }

        if(dp[mask] != 2) {
            return dp[mask];
        }

        for(int i = 0; i < n; i++) {
            int num = nums[i];
            int bitFilter = (1<<(i));
            int setBit = mask & bitFilter;
            if(setBit) {
                continue;
            }
            
            int newSum = curSum + num;
            if(newSum > groupSum){
                continue;
            }
            newSum %= groupSum;
            int newMask = mask | bitFilter;
            bool attempt = r(newMask, newSum, groupSum, nums);
            if(attempt) {
                dp[mask] = true;
                return true;
            }
        }
        dp[mask] = false;
        return false;
    }

    int filledMask;
    int n;
    vector<char> dp;
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        //if sum is not divisble by k, clearly impossible
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % k != 0) {
            return false;
        }

        //sort descending
        //pq which returns smallest group sum
        sort(nums.begin(), nums.end(), greater<int>());

        //if any of the elements > sum / k, clearly impossible
        int groupSum = sum / k;
        int maxElement = nums.front();
        if(maxElement > groupSum) {
            return false;
        }
        n = nums.size();
        filledMask = (1 << n)-1;
        dp.resize(filledMask, 2);
        return r(0, 0, groupSum, nums);
    }
};